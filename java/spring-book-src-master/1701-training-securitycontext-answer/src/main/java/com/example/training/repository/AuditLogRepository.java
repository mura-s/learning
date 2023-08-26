package com.example.training.repository;

import com.example.training.entity.AuditLog;

public interface AuditLogRepository {
    void insert(AuditLog auditLog);
}
