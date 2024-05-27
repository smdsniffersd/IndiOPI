#include "pch.h"
#include "CppUnitTest.h"
#include "input.h"
#include <sstream>
#include <iostream>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Tests
{
    TEST_CLASS(InputTests)
    {
    public:
        // ���� �������� ����� ����������� ���������� ��������� � ��������
        TEST_METHOD(CorrectInputTest)
        {
            unsigned int NumbersTroniks;
            int* Troniks;

            std::istringstream input_stream("3\n5\n2\n7\n");
            std::streambuf* orig = std::cin.rdbuf(input_stream.rdbuf());

            getInput(NumbersTroniks, Troniks);
            std::cin.rdbuf(orig);

            Assert::AreEqual(static_cast<unsigned int>(3), NumbersTroniks);
            Assert::IsNotNull(Troniks);
            Assert::AreEqual(5, Troniks[0]);
            Assert::AreEqual(2, Troniks[1]);
            Assert::AreEqual(7, Troniks[2]);

            delete[] Troniks;
        }

        // �������� �� double ���������� ���������
        TEST_METHOD(DoubleInputTest)
        {
            std::istringstream input_stream("3.5\n");
            std::streambuf* old_cin = std::cin.rdbuf();
            std::cin.rdbuf(input_stream.rdbuf());

            Assert::ExpectException<std::invalid_argument>([] {
                unsigned int NumbersTroniks;
                int* Troniks;

                getInput(NumbersTroniks, Troniks);
                });

            std::cin.rdbuf(old_cin);
        }

        // ���� �������� �� ������������� ���������� ���������
        TEST_METHOD(NegativeInputTest)
        {
            unsigned int NumbersTroniks;
            int* Troniks;

            std::istringstream input_stream("-3\n");
            std::streambuf* orig = std::cin.rdbuf(input_stream.rdbuf());

            try
            {
                getInput(NumbersTroniks, Troniks);

                Assert::Fail(L"���������� �� ���� �������");
            }
            catch (const std::invalid_argument& e)
            {
                Assert::IsTrue(std::string(e.what()).find("�������� ���������� ���������") != std::string::npos);
            }

            std::cin.rdbuf(orig);
        }

        TEST_METHOD(MinimumInputTest)
        {
            unsigned int NumbersTroniks;
            int* Troniks;

            std::istringstream input_stream("1\n5\n");
            std::streambuf* orig = std::cin.rdbuf(input_stream.rdbuf());

            getInput(NumbersTroniks, Troniks);

            Assert::AreEqual(static_cast<unsigned int>(1), NumbersTroniks);
            Assert::IsNotNull(Troniks);
            Assert::AreEqual(5, Troniks[0]);

            delete[] Troniks;

            std::cin.rdbuf(orig);
        }

        // ���� �������� ����� ������������� ���������� ���������
        TEST_METHOD(TestGetInputWithThousandTroniks)
        {
            unsigned int NumbersTroniks;
            int* Troniks = nullptr;
            std::stringstream input;

            input << "1000\n";

            for (int i = 0; i < 1000; ++i) {
                input << "10\n";
            }

            std::cin.rdbuf(input.rdbuf());

            try {
                getInput(NumbersTroniks, Troniks);

                Assert::AreEqual(1000u, NumbersTroniks, L"���������� ��������� ������ ���� 1000");

                for (unsigned int i = 0; i < NumbersTroniks; i++) {
                    Assert::AreEqual(10, Troniks[i], L"���������� �������� � ������ �������� ������ ���� 10");
                }

                delete[] Troniks;

            }
            catch (const std::invalid_argument& e) {
                Assert::Fail(L"���������� �� ������ ���� ���� �������");
            }
        }


        // ���� �� 0 �������� �������� � ��������
        TEST_METHOD(TestGetInputWithZeroSockets)
        {
            unsigned int NumbersTroniks;
            int* Troniks = nullptr;

            std::stringstream input;

            input << "1\n";
            input << "0\n";

            std::cin.rdbuf(input.rdbuf());

            try {
                getInput(NumbersTroniks, Troniks);
                Assert::Fail(L"��������� ���������� ��� ����� 0 ��������");
            }
            catch (const std::invalid_argument& e) {

                Assert::AreEqual("�������� ���������� ��������", e.what(), L"��������� ���������� ������ ���� '�������� ���������� ��������'");
            }

            if (Troniks != nullptr) {
                delete[] Troniks;
            }
        }

        // ����(1) �������� �� ���������� ��������
        TEST_METHOD(MinimumTronikInputTest)
        {
            unsigned int NumbersTroniks;
            int* Troniks;

            std::istringstream input_stream("1\n1\n");
            std::streambuf* orig = std::cin.rdbuf(input_stream.rdbuf());

            getInput(NumbersTroniks, Troniks);

            Assert::AreEqual(static_cast<unsigned int>(1), NumbersTroniks);
            Assert::IsNotNull(Troniks);
            Assert::AreEqual(1, Troniks[0]);

            delete[] Troniks;

            std::cin.rdbuf(orig);
        }

        // ����(2) �������� �� ���������� ��������
        TEST_METHOD(MaximumTronikInputTest)
        {
            unsigned int NumbersTroniks;
            int* Troniks;

            std::istringstream input_stream("1\n1000\n");
            std::streambuf* orig = std::cin.rdbuf(input_stream.rdbuf());

            getInput(NumbersTroniks, Troniks);

            Assert::AreEqual(static_cast<unsigned int>(1), NumbersTroniks);
            Assert::IsNotNull(Troniks);
            Assert::AreEqual(1000, Troniks[0]);

            delete[] Troniks;

            std::cin.rdbuf(orig);
        }

        // ���� �������� ��������� ���������� �������� � ��������

        TEST_METHOD(TestGetInputWithTooManySockets)
        {
            unsigned int NumbersTroniks;
            int* Troniks = nullptr;

            std::stringstream input;

            input << "1\n";
            input << "100001\n";

            std::cin.rdbuf(input.rdbuf());

            try {
                getInput(NumbersTroniks, Troniks);
                Assert::Fail(L"��������� ���������� ��� ����� 1001 �������");
            }
            catch (const std::invalid_argument& e) {

                Assert::AreEqual("�������� ���������� ��������", e.what(), L"��������� ���������� ������ ���� '�������� ���������� ��������'");
            }

            if (Troniks != nullptr) {
                delete[] Troniks;
            }
        }
         // ���� �� �������� �������� �������������� ��������
        TEST_METHOD(VeryNegativeTronikInputTest)
        {
            unsigned int NumbersTroniks;
            int* Troniks;

            std::istringstream input_stream("1\n-1000000\n");
            std::streambuf* orig = std::cin.rdbuf(input_stream.rdbuf());

            try
            {
                getInput(NumbersTroniks, Troniks);

                Assert::Fail(L"���������� �� ���� �������");
            }
            catch (const std::invalid_argument& e)
            {
                Assert::IsTrue(std::string(e.what()).find("�������� ���������� ��������") != std::string::npos);
            }

            std::cin.rdbuf(orig);
        }
    };
}