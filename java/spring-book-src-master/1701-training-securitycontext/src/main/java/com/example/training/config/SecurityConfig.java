package com.example.training.config;

import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;
import org.springframework.http.HttpMethod;
import org.springframework.security.config.annotation.web.builders.HttpSecurity;
import org.springframework.security.config.annotation.web.configuration.EnableWebSecurity;
import org.springframework.security.core.userdetails.User;
import org.springframework.security.core.userdetails.UserDetails;
import org.springframework.security.core.userdetails.UserDetailsService;
import org.springframework.security.provisioning.InMemoryUserDetailsManager;
import org.springframework.security.web.SecurityFilterChain;
import org.springframework.security.web.util.matcher.AntPathRequestMatcher;

@Configuration
@EnableWebSecurity
public class SecurityConfig {
    @Bean
    public SecurityFilterChain securityFilterChain(HttpSecurity http) throws Exception {
        http
            .authorizeHttpRequests()
            .requestMatchers(HttpMethod.POST, "/admin/**").hasRole("ADMIN")
            .requestMatchers("/admin/**").hasAnyRole("ADMIN", "STAFF")
            .anyRequest().permitAll()
        .and()
            .formLogin()
            .loginPage("/login")
            .defaultSuccessUrl("/admin/training/display-list")
            .failureUrl("/login?failure")
        .and()
            .exceptionHandling()
            .accessDeniedPage("/display-access-denied");

        // for h2-console        
        http
            .csrf().ignoringRequestMatchers(AntPathRequestMatcher.antMatcher("/h2-console/**")).and()
            .headers().frameOptions().sameOrigin();        
        
        return http.build();
    }

    @Bean
    public UserDetailsService userDetailsService () {
        UserDetails taro = User.builder()
                .username("taro").password("{noop}taro123").roles("ADMIN").build();
        UserDetails jiro = User.builder()
                .username("jiro").password("{noop}jiro123").roles("STAFF").build();
        UserDetails saburo = User.builder()
                .username("saburo").password("{noop}saburo123").roles("GUEST").build();
        return new InMemoryUserDetailsManager(taro, jiro, saburo);
    }
}
