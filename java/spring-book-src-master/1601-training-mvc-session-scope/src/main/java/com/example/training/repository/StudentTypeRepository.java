package com.example.training.repository;

import java.util.List;

import com.example.training.entity.StudentType;

public interface StudentTypeRepository {
	List<StudentType> selectAll();

	StudentType selectByCode(String studentTypeCode);
}
