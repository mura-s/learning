package com.example.training.repository;

import com.example.training.entity.StudentType;

public interface StudentTypeRepository {
	StudentType selectByCode(String studentTypeCode);
}
