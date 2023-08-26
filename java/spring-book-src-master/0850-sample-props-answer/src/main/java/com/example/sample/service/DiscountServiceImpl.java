package com.example.sample.service;

import org.springframework.stereotype.Service;

@Service
public class DiscountServiceImpl implements DiscountService {

    private final DiscountProperties discountProperties;

    public DiscountServiceImpl(DiscountProperties discountProperties) {
        this.discountProperties = discountProperties;
    }

    @Override
    public int calculateDiscountPrice(int originalPrice) {

        double discountRate = discountProperties.getRate();
        int discountMax = discountProperties.getMax();
        
        System.out.println("ディスカウント率:" + discountRate);
        System.out.println("ディスカウント上限:" + discountMax);

        int discount = (int)(originalPrice * discountRate);

        if (discount > discountMax) {
            System.out.println("ディスカウント額が上限値を超えました。discount=" + discount + " max=" + discountMax);
            discount = discountMax;
        }

        return originalPrice - discount;
    }
}
