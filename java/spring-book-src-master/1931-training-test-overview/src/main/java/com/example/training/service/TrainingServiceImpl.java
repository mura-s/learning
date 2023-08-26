package com.example.training.service;

import com.example.training.entity.Training;
import com.example.training.repository.TrainingRepository;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;

import java.util.List;

@Service
@Transactional
public class TrainingServiceImpl implements TrainingService {

    private final TrainingRepository trainingRepository;

    public TrainingServiceImpl(TrainingRepository trainingRepository) {
        this.trainingRepository = trainingRepository;
    }

    @Override
    public List<Training> findAll() {
        return trainingRepository.selectAll();
    }

    @Override
    public Training findById(String id) {
        return trainingRepository.selectById(id);
    }

}
