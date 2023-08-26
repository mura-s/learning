package com.example.training.controller;

import static org.hamcrest.Matchers.*;
import static org.mockito.ArgumentMatchers.any;
import static org.mockito.Mockito.*;
import static org.springframework.test.web.servlet.request.MockMvcRequestBuilders.*;
import static org.springframework.test.web.servlet.result.MockMvcResultMatchers.*;

import java.util.ArrayList;
import java.util.List;

import org.junit.jupiter.api.Test;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.autoconfigure.web.servlet.WebMvcTest;
import org.springframework.boot.test.mock.mockito.MockBean;
import org.springframework.test.web.servlet.MockMvc;

import com.example.training.entity.Training;
import com.example.training.input.TrainingAdminInput;
import com.example.training.service.TrainingAdminService;


@WebMvcTest(TrainingAdminController.class)
class TrainingAdminControllerTest {

    @Autowired
    MockMvc mockMvc;

    @MockBean
    TrainingAdminService trainingAdminService;

    @MockBean
    TrainingAdminSession trainingAdminSession;

    @Test
    void test_displayList() throws Exception {
        List<Training> trainings = new ArrayList<>();
        Training training = new Training();
        training.setTitle("Java研修");
        trainings.add(training);
        training = new Training();
        training.setTitle("ビジネスマナー研修");
        trainings.add(training);
        doReturn(trainings).when(trainingAdminService).findAll();

        mockMvc.perform(
                        get("/admin/training/display-list")
                )
                .andExpect(content().string(containsString("<span>Java研修</span>")))
                .andExpect(content().string(containsString("<span>ビジネスマナー研修"
                        + "</span>")))
        ;
    }

    @Test
    void test_displayUpdateForm() throws Exception {
        Training training = new Training();
        training.setTitle("Java研修");
        doReturn(training).when(trainingAdminService).findById("t01");

        mockMvc.perform(
                        get("/admin/training/display-update-form")
                                .param("trainingId", "t01")
                )
                .andExpect(content().string(containsString("Java研修")))
        ;
    }

    @Test
    void test_validateUpdateInput() throws Exception {
        mockMvc.perform(
                        post("/admin/training/validate-update-input")
                                .param("title", "Java研修")
                                .param("startDateTime", "2021/12/01 09:30")
                                .param("endDateTime", "2021/12/05 17:00")
                                .param("reserved", "2")
                                .param("capacity", "10")
                )
                .andExpect(view().name("admin/training/updateConfirmation"))
                .andExpect(content().string(containsString("Java研修")))
        ;

        verify(trainingAdminSession).setTrainingAdminInput(any());
    }

    @Test
    void test_validateUpdateInput_入力エラー() throws Exception {
        mockMvc.perform(
                        post("/admin/training/validate-update-input")
                )
                .andExpect(view().name("admin/training/updateForm"))
                .andExpect(model().attributeHasFieldErrorCode("trainingAdminInput", "title", "NotBlank"))
                .andExpect(model().attributeHasFieldErrorCode("trainingAdminInput", "startDateTime", "NotNull"))
                .andExpect(model().attributeHasFieldErrorCode("trainingAdminInput", "endDateTime", "NotNull"))
                .andExpect(model().attributeHasFieldErrorCode("trainingAdminInput", "reserved", "NotNull"))
                .andExpect(model().attributeHasFieldErrorCode("trainingAdminInput", "capacity", "NotNull"))
        ;
    }

    @Test
    void test_validateUpdateInput_入力エラー2() throws Exception {
        mockMvc.perform(
                        post("/admin/training/validate-update-input")
                                .param("title", "Java研修")
                                .param("startDateTime", "2021/12/01 09:30")
                                .param("endDateTime", "2021/12/05 17:00")
                                .param("reserved", "-1")
                                .param("capacity", "-1")
                )
                .andExpect(view().name("admin/training/updateForm"))
                .andExpect(model().attributeHasFieldErrorCode("trainingAdminInput", "reserved", "Min"))
                .andExpect(model().attributeHasFieldErrorCode("trainingAdminInput", "capacity", "Min"))
        ;
    }

    @Test
    void test_update() throws Exception {
        TrainingAdminInput trainingAdminInput = new TrainingAdminInput();
        trainingAdminInput.setId("t01");
        doReturn(trainingAdminInput).when(trainingAdminSession).getTrainingAdminInput();

        mockMvc.perform(
                        post("/admin/training/update")
                                .param("update", "")
                )
                .andExpect(status().is3xxRedirection())
                .andExpect(redirectedUrl(("/admin/training/display-update-completion")))
                .andExpect(flash().attribute("trainingId", "t01"))
        ;

        verify(trainingAdminService).update(any());
        verify(trainingAdminSession).clearData();
    }

    @Test
    void test_displayUpdateCompletion() throws Exception {
        mockMvc.perform(
                        get("/admin/training/display-update-completion")
                )
                .andExpect(content().string(containsString("<h1>研修更新完了</h1>")))
        ;
    }


}