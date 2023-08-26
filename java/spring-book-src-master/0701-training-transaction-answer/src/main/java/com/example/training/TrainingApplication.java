package com.example.training;

import javax.sql.DataSource;

import org.slf4j.LoggerFactory;
import org.springframework.context.ApplicationContext;
import org.springframework.context.annotation.AnnotationConfigApplicationContext;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.ComponentScan;
import org.springframework.context.annotation.Configuration;
import org.springframework.jdbc.core.JdbcTemplate;
import org.springframework.jdbc.datasource.embedded.EmbeddedDatabase;
import org.springframework.jdbc.datasource.embedded.EmbeddedDatabaseBuilder;
import org.springframework.jdbc.datasource.embedded.EmbeddedDatabaseType;
import org.springframework.jdbc.support.JdbcTransactionManager;
import org.springframework.transaction.annotation.EnableTransactionManagement;

import com.example.training.entity.Reservation;
import com.example.training.input.ReservationInput;
import com.example.training.service.ReservationService;

import ch.qos.logback.classic.Level;
import ch.qos.logback.classic.Logger;

@Configuration
@ComponentScan
@EnableTransactionManagement
public class TrainingApplication {
    @Bean
    public DataSource dataSource() {
        EmbeddedDatabase dataSource = new EmbeddedDatabaseBuilder()
                .addScripts("schema.sql", "data.sql")
                .setType(EmbeddedDatabaseType.H2).build();
        return dataSource;
    }

    @Bean
    public JdbcTemplate jdbcTemplate(DataSource dataSource) {
        return new JdbcTemplate(dataSource);
    }

    @Bean
    public JdbcTransactionManager transactionManager(DataSource dataSource) {
        return new JdbcTransactionManager(dataSource);
    }

    public static void main(String[] args) {
        ApplicationContext context = new AnnotationConfigApplicationContext(TrainingApplication.class);
        // トランザクション制御のログを出力してくれるように設定
        ((Logger) LoggerFactory.getLogger(JdbcTransactionManager.class)).setLevel(Level.DEBUG);
        ReservationService reservationService = context.getBean(ReservationService.class);

        ReservationInput reservationInput = new ReservationInput();
        reservationInput.setName("東京太郎");
        reservationInput.setPhone("090-0000-0000");
        reservationInput.setEmailAddress("taro@example.com");
        reservationInput.setStudentTypeCode("FREELANCE");
        reservationInput.setTrainingId("t01");

        Reservation reservation = reservationService.reserve(reservationInput);

        System.out.println("予約の処理が完了しました。 予約ID=" + reservation.getId());
    }

}

