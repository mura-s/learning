package com.example.shopping.service;

import java.time.LocalDateTime;
import java.util.ArrayList;
import java.util.List;
import java.util.UUID;

import com.example.shopping.input.CartInput;
import com.example.shopping.input.CartItemInput;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Propagation;
import org.springframework.transaction.annotation.Transactional;

import com.example.shopping.entity.Order;
import com.example.shopping.entity.OrderItem;
import com.example.shopping.entity.Product;
import com.example.shopping.exception.StockShortageException;
import com.example.shopping.input.OrderInput;
import com.example.shopping.repository.OrderItemRepository;
import com.example.shopping.repository.OrderRepository;
import com.example.shopping.repository.ProductRepository;

@Service
@Transactional
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
    @Transactional(propagation = Propagation.SUPPORTS)
    public int calculateTotalAmount(List<CartItemInput> cartItems) {
        int totalAmount = 0;
        for (CartItemInput cartItem : cartItems) {
            totalAmount += (cartItem.getProductPrice() * cartItem.getQuantity());
        }
        return totalAmount;
    }

    @Override
    @Transactional(propagation = Propagation.SUPPORTS)
    public int calculateTax(int price) {
        return (int) (price * 1.1);
    }

    @Override
    public Order placeOrder(OrderInput orderInput, CartInput cartInput) {
        Order order = new Order();
        order.setId(UUID.randomUUID().toString());
        order.setCustomerName(orderInput.getName());
        order.setCustomerAddress(orderInput.getAddress());
        order.setCustomerPhone(orderInput.getPhone());
        order.setCustomerEmailAddress(orderInput.getEmailAddress());
        order.setOrderDateTime(LocalDateTime.now());
        order.setPaymentMethod(orderInput.getPaymentMethod());
        int totalAmount = calculateTotalAmount(cartInput.getCartItemInputs());
        int billingAmount = calculateTax(totalAmount);
        order.setBillingAmount(billingAmount);
        orderRepository.insert(order);
        List<OrderItem> orderItems = new ArrayList<>();
        for (CartItemInput cartItem : cartInput.getCartItemInputs()) {
            Product product = productRepository.selectById(cartItem.getProductId());
            int afterStock = product.getStock() - cartItem.getQuantity();
            if (afterStock < 0) {
                throw new StockShortageException("在庫が足りません");
            }
            product.setStock(afterStock);
            productRepository.update(product);
            OrderItem orderItem = new OrderItem();
            orderItem.setId(UUID.randomUUID().toString());
            orderItem.setOrderId(order.getId());
            orderItem.setProduct(product);
            orderItem.setPriceAtOrder(cartItem.getProductPrice());
            orderItem.setQuantity(cartItem.getQuantity());
            orderItemRepository.insert(orderItem);
            orderItems.add(orderItem);
        }
        order.setOrderItems(orderItems);
        return order;
    }
}