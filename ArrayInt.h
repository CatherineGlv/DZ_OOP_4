#pragma once
#ifndef ARRAYINT_H
#define ARRAYINT_H
#include <cassert> // ��� assert()


class ArrayInt
{
private:
	int m_length;
	int* m_data;
public:
	ArrayInt() : m_length(0), m_data(nullptr)
	{ }
	ArrayInt(int length) :
		m_length(length)
	{
		assert(length >= 0);
		if (length > 0)
			m_data = new int[length];
		else
			m_data = nullptr;
	}
	~ArrayInt()
	{
		delete[] m_data;
	}

#endif

	void erase()
	{
		delete[] m_data;
		// ����� ��� ����� ������� m_data �������� nullptr, ����� �� ������ ��
		// ���� �������� ���������

		m_data = nullptr;
		m_length = 0;
	} 
	int getLength() {
		return m_length;
	}

	int& operator[](int index)
	{
		assert(index >= 0 && index < m_length);
		return m_data[index];
	}

	// ������� resize �������� ������ �������. ��� ������������ ��������
	//�����������. ������� ���������

	void resize(int newLength)
	{
		// ���� ������ ��� ������ ����� � return
		if (newLength == m_length)
			return;

		// ���� ����� ������� ������ ������ � ������ ��� � ����� return
		if (newLength <= 0)
		{
			erase();
			return;
		}

		// ������ �����, ��� newLength >0
		// �������� ����� ������
		int* data = new int[newLength];

		// ����� ����� ����������� � ����������� ���������� ��������� � �����
		//������
		// ����� ����������� ������� ���������, ������� �� ���� � ������� ��
		//��������
		if (m_length > 0)
		{
			int elementsToCopy = (newLength > m_length) ? m_length : newLength;
			
			// ���������� �������� ��������
			for (int index = 0; index < elementsToCopy; ++index)
				data[index] = m_data[index];
		}
		
		// ������� ������ ������, ��� ��� �� ��� ��� �� �����
		delete[] m_data;

		// � ���������� ������ ������� ������� �����! �������� ��������,
		//m_data ��������� �� ��� �� �����, �� ������� ��������� ��� ����� �����������
		//���������� ������.���������
		// ������ ���� ����������� ���������� � ��� �� ����� ����������, ����� ������ �� ������� ���������

		m_data = data;
		m_length = newLength;
	}

	void insertBefore(int value, int index)
	{
		// �������� ������������ ������������� �������
		assert(index >= 0 && index <= m_length);

		// ������� ����� ������ �� ���� ������� ������ ������� �������
		int* data = new int[m_length + 1];

		// �������� ��� �������� �� index-�
		for (int before = 0; before < index; ++before)
			data[before] = m_data[before];

		// ��������� ����� ������� � ����� ������
		data[index] = value;

		// �������� ��� �������� ����� ������������ ��������
		for (int after = index; after < m_length; ++after)
			data[after + 1] = m_data[after];

		// ������� ������ ������ � ���������� ������ ���� �����
		delete[] m_data;
		
		m_data = data;
		++m_length;
	}
	void push_back(int value) { insertBefore(value, m_length); }

	// 1 -------------------------------------------------------------
	void Resize(int* m_data, int m_length)
	{
		int* resize_m_data = new int[m_length - 1];
		
		for (int i = 0; i < m_length - 1; i++)
			resize_m_data[i] = m_data[i];
		
		delete[] m_data;
		
		m_data = resize_m_data;
	}

	// 2 -------------------------------------------------------------
	void Resize1(int* m_data, int m_length)
	{
		int* resize1_m_data = new int[m_length];

		for (int i = 0; i < m_length; i++)
			resize1_m_data[i] = m_data[i];
		
		delete[] m_data;
		
		m_data = resize1_m_data;
	}

};