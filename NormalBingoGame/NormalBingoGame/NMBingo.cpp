#include <iostream>
#include <time.h>

using namespace std;

int main()
{
	srand((unsigned int)time(0));

	// 5X5 ������
	int iNumber[25] = {};

	for (int i = 0; i < 25; ++i)
	{
		iNumber[i] = i + 1;
	}

	int idx1, idx2, iTemp;

	// ���ڸ� �����ش�.
	for (int i = 0; i < 100; ++i)
	{
		idx1 = rand() % 25;
		idx2 = rand() % 25;

		iTemp = iNumber[idx1];
		iNumber[idx1] = iNumber[idx2];
		iNumber[idx2] = iTemp;
	}

	int iBingo = 0;

	while (1)
	{
		// *�� ����
		// �������� �ﰢ������ ������Ʈ�ϱ����ؼ� ���ȭ���� �����ְ� ���θ����.
		system("cls");

		// ���� 5X5�� ����Ѵ�.
		for (int i = 0; i < 5; ++i)
		{
			for (int j = 0; j < 5; ++j)
			{
				// ���ڸ� *�� ������Ʈ
				if (iNumber[i * 5 + j] == INT_MAX)
					cout << "*\t";
				// �״�� ���
				else
					cout << iNumber[i * 5 + j] << "\t";
			}
			cout << endl;
		}

		cout << "Bingo Line :" << iBingo << endl;

		// �ټ��� 5 �̻��� ��� ������ �����Ѵ�.
		if (iBingo >= 5)
			break;

		cout << "���ڸ� �Է��ϼ��� (0: ����)";

		int iInput;
		cin >> iInput;

		if (iInput == 0)
			break;

		else if (iInput < 1 || iInput>25)
			continue;

		// �ߺ��Է��� üũ�ϱ� ���� �����̴�. �⺻������ �ߺ��Ǿ��ٶ�� �ϱ����� true�� ��Ҵ�.
		bool bAcc = true;

		// ��� ���ڸ� ���ʴ�� �˻��ؼ� �Է��� ���ڿ� ���� ���ڰ� �ִ����� ã�Ƴ���.
		for (int i = 0; i < 25; ++i)
		{
			// ���� ���ڰ� ���� ���
			if (iInput == iNumber[i])
			{
				// ���ڸ� ã���� ��� �ߺ��� ���ڰ� �ƴϹǷ�
				// bAcc ������ false�� ������ش�.
				bAcc = false;

				// ���ڸ� *�� �����ϱ� ���� Ư���� ���� INT_MAX�� ���ش�.
				// INT_MAX���� Ư����(2147483647)�� ����ִ�.
				iNumber[i] = INT_MAX;

				// ���̻� �ٸ� ���ڸ� ã�ƺ� �ʿ䰡 �����Ƿ�
				// for���� ����������.
				break;
			}
		}

		// bAcc ������ true�� ��� �ߺ��� ���ڸ� �Է��ؼ� ���ڸ� *��
		// �ٲ��� �������Ƿ� �ٽ� �Է¹ް�  continue ���ش�.
		if (bAcc)
			continue;

		// ���� �� ���� üũ�ϴ� ���� �Ź� ���ڸ� �Է��Ҷ����� ó������
		// ���� ī��Ʈ �Ұ��̴�. �׷��Ƿ� iBingo ������ 0���� �Ź�
		// �ʱ�ȭ�ϰ� ���Ӱ� �� ���� �����ֵ��� �Ѵ�.
		iBingo = 0;

		// ����,���� �� ���� �����ش�.
		int iStar1 = 0, iStar2 = 0;
		for (int i = 0; i < 5; ++i)
		{
			// ������ üũ�ϱ� ���� ���� 0���� �� ������ �ʱ�ȭ�Ѵ�.
			iStar1 = iStar2 = 0;
			for (int j = 0; j < 5; ++j)
			{
				// ���� �� ������ �����ش�.
				if (iNumber[i * 5 + j] == INT_MAX)
					++iStar1;

				// ���� �� ������ �����ش�.
				if (iNumber[i + 5 * j] == INT_MAX)
					++iStar2;
			}

			// j for���� ���������� ���� ���� ���� ���� �� ������ �����
			// iStar1 ������ ���� �ȴ�.
			// iStar1 ���� 5�̸� ������ ��� *�̶�� �ǹ��̹Ƿ� ���� �� ī��Ʈ�� �߰��Ѵ�.
			if (iStar1 == 5 || iStar2 == 5)
				++iBingo;
		}

		// ���� ��� -> ������ �ϴ� �밢�� üũ
		iStar1 = 0;
		for (int i = 0; i < 25; i += 6)
		{
			if (iNumber[i] == INT_MAX)
				++iStar1;
		}

		if (iStar1 == 5)
			++iBingo;

		// ������ ��� -> ���� �ϴ� �밢�� üũ
		iStar1 = 0;
		for (int i = 4; i < 25; i += 4)
		{
			if (iNumber[i] == INT_MAX)
				++iStar1;
		}

		if (iStar1 == 5)
			++iBingo;
	}
	return 0;
}