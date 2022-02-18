// ���Ʈ�� ���Ӿ�ī���� - 17ȭ. �Լ�(3)����

#include <stdio.h>

// �Լ�
// �Լ��� ����� �����س����� �ڵ尡 ����ȭ�ǰ�, ���ȭ �۾��� �� �س��ٸ�
// ���Ŀ� ������ ���α׷��� ������ �� �����ϰ� ���� ������ �� �ִ� ����� �ȴ�.

// Factorial �Լ�
// �Լ��� �ҽ��ڵ� ��ü�� ���� �޸𸮿� ����Ǵ� ���� �ƴ϶�
// �Լ��� ȣ�������ν� ������ �ʱ�ȭ�Ǵ� ������ �޸𸮷� ����ȴ�.
// ���� ���� �Լ��� ������ �����Ѵٰ� �ص� ���ÿ� �Լ� �޸𸮰� ��� ���̴� ���� �ƴ϶�
// �ϳ��� �Լ� ���� �ȿ��� ���� �޸𸮰� ���̰� �ȴ�.
int Factorial(int _iNum) {
	int iValue = 1;

	for (int j = 0; j < _iNum - 1; ++j) {
		iValue *= (j + 2);
	}

	return iValue;
}

// ���(Recursive)�Լ�
// ������, ������ ����
// ����, �ӵ��� ������.

// �ݵ�� Ż�� ������ �־�� �Ѵ�.
// Ż������ ���Ѵٸ� stack overflow �߻�

// ����Լ� Factorial
int Factorial_Re(int _iNum) {
	if (_iNum == 1) {
		return 1;
	}
	
	return _iNum * Factorial_Re(_iNum - 1);
}

// �Ǻ���ġ ����
// 1 1 2 3 5 8 13 21 34 55 ...
// �Ǿ��� 0 1 �� �����Ұ����� 1 1�� �����Ұ������� ����
int Fibonacci(int _iNum) {
	if (_iNum == 1 || _iNum == 2) {
		return 1;
	}

	int iPrev1 = 1;
	int iPrev2 = 1;
	int iValue = 0;

	for (int i = 0; i < _iNum - 2; ++i) {
		iValue = iPrev1 + iPrev2;
		iPrev1 = iPrev2;
		iPrev2 = iValue;
	}
	return iValue;
}

// ����Լ� - �Ǻ���ġ ����
int Fibonacci_Re(int _iNum) {
	if (_iNum == 1 || _iNum == 2) {
		return 1;
	}
	return Fibonacci_Re(_iNum - 1) + Fibonacci_Re(_iNum - 2);
}


int main() {
	int iValue = Factorial(4);
	iValue = Factorial(10);
	iValue = Factorial_Re(10);

	iValue = Fibonacci(8);
	iValue = Fibonacci_Re(8);

	/* �迭 */
	// �޸𸮰� ������
	int iArray[10] = {};

	iArray[12] = 10; // ���� �߻�
	// �޸𸮰� ���������� ����Ǵµ� �迭�� ũ�⸦ ���� 12���� �ε����� ���� �����Ͽ���.
	// �׷��� �쿬���� ���� ����Ǿ��� 'iValue'������ ������ ���� ��ġ�� 12�������� ������
	// ����׸� �������� ���ڱ� iValue���� 10���� �ʱ�ȭ �Ǿ���.
	// �̷��� ������ ����� �ÿ��� ������ ���� �ʱ� ������ �߸��� ��ġ�� ã�Ⱑ �ſ� ��ư�
	// ���� �������� ���� ���� ������ ����Ǿ� ��Ȳ������ ���� ���� �� �ִ�.
	// ���� �迭�� ũ��, ���� ���� �ε����� �˸°� �����ϴ� ���� �ſ� �߿��ϴ�.

	int iData = 0;

	int iArray2[100] = {};

	return 0;
}