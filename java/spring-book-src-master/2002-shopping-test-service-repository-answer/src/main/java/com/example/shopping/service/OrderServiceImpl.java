package com.example.shopping.service;

import java.time.LocalDateTime;
import java.util.ArrayList;
import java.util.List;
import java.util.UUID;

import com.example.shopping.input.OrderInput;
import org.springframework.stereotype.Service;

import com.example.shopping.entity.Order;
import com.example.shopping.entity.OrderItem;
import com.example.shopping.entity.Product;
import com.example.shopping.exception.StockShortageException;
import com.example.shopping.input.CartInput;
import com.example.shopping.input.CartItemInput;
import com.example.shopping.repository.OrderItemRepository;
import com.example.shopping.repository.OrderRepository;
import com.example.shopping.repository.ProductRepository;

@Service
public class OrderServiceImpl implements OrderService {
    private final OrderRepository orderRepository;
    private final OrderItemRepository orderItemRepository;
    private final ProductRepository productRepository;

    public OrderServiceImpl(OrderRepository orderRepository, OrderItemRepository orderItemRepository, ProductRepository productRepository) {
        this.orderRepository = orderRepository;
        this.orderItemRepository = orderItemRepository;
        this.productRepository = productRepository;
    }

    @Override
    public Order placeOrder(OrderInput orderInput, CartInput cartInput) {
        // Repositoryに渡す注文オブジェクトを生成
        Order order = new Order();
        // IDはUUID(Universally Unique Identifier。ランダムなIDを生成する際に用いられる標準的な仕組み)を使用
        order.setId(UUID.randomUUID().toString());
        // 引数で渡された注文情報(OrderInput)の情報をOrderオブジェクトに格納
        order.setCustomerName(orderInput.getName());
        order.setCustomerAddress(orderInput.getAddress());
        order.setCustomerPhone(orderInput.getPhone());
        order.setCustomerEmailAddress(orderInput.getEmailAddress());
        order.setOrderDateTime(LocalDateTime.now());
        order.setPaymentMethod(orderInput.getPaymentMethod());
        // 合計額(税抜)を計算
        int totalAmount = calculateTotalAmount(cartInput.getCartItemInputs());
        // 請求額(税込)を計算
        int billingAmount = calculateTax(totalAmount);
        order.setBillingAmount(billingAmount);
        // 注文データをデータベースに挿入
        orderRepository.insert(order);
        List<OrderItem> orderItems = new ArrayList<>();
        // カートの中の商品の数だけ繰り返す
        for (CartItemInput cartItem : cartInput.getCartItemInputs()) {
            // 商品データをデータベースから取得
            Product product = productRepository.selectById(cartItem.getProductId());
            int afterStock = product.getStock() - cartItem.getQuantity();
            // 在庫が足りない場合は例外をスローする
            if (afterStock < 0) {
                throw new StockShortageException("在庫が足りません");
            }
            // 在庫数を更新
            product.setStock(afterStock);
            // データベースの商品データを更新
            productRepository.update(product);
            // Repositoryに渡す注文明細オブジェクトを生成。数量などを格納
            OrderItem orderItem = new OrderItem();
            orderItem.setId(UUID.randomUUID().toString());
            orderItem.setOrderId(order.getId());
            orderItem.setProductId(product.getId());
            orderItem.setPriceAtOrder(cartItem.getProductPrice());
            orderItem.setQuantity(cartItem.getQuantity());
            // 注文明細データをデータベースに挿入
            orderItemRepository.insert(orderItem);
            orderItems.add(orderItem);
        }
        order.setOrderItems(orderItems);
        // 注文処理後のOrderオブジェクトを戻り値で返す
        return order;
    }

    private int calculateTotalAmount(List<CartItemInput> cartItems) {
        int totalAmount = 0;
        for (CartItemInput cartItem : cartItems) {
            totalAmount += (cartItem.getProductPrice() * cartItem.getQuantity());
        }
        return totalAmount;
    }

    private int calculateTax(int price) {
        return (int) (price * 1.1);
    }
}