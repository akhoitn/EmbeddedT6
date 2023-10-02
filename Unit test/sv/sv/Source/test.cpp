#include "pch.h"
#include "gtest/gtest.h"
#include "sv.hpp"




TEST(TestCaseName, TestName) {
    EXPECT_EQ(1, 1);
    EXPECT_TRUE(true);
}

TEST(StudentManagementTest, AddAndDelStudent) {
    StudentManagement ql;
    ql.addStudent(1, "K", 9.5);
    ql.addStudent(2, "H", 6.4);

    ASSERT_EQ(ql.getListStudent().size(), 2);

    ql.delStudent(1);

    ASSERT_EQ(ql.getListStudent().size(), 1);
}

TEST(StudentManagementTest, Score) {
    StudentManagement ql;
    ql.addStudent(1, "K", 9.5);
    ql.addStudent(2, "H", 6.4);
    ASSERT_DOUBLE_EQ(ql.getScore(), 7.95);
}

TEST(StudentManagementTest, delStudentEmpty) {
    StudentManagement ql;
    ql.addStudent(1, "K", 9.5);
    ql.addStudent(2, "H", 6.4);

    ql.delStudent(3);
    ASSERT_EQ(ql.getListStudent().size(), 2);
}

TEST(StudentManagementTest, listEmpty) {
    StudentManagement ql;

    ASSERT_EQ(ql.getListStudent().size(), 0);
}