#pragma once
#include <iostream>
#include <time.h>
using namespace std;

class melodyInput {
private:
	int pitch;
	int measure;
	int meter;
	int gesture;
	int chord;
	int *pitchPoint;
	int *gesPoint;
	int *chordPoint;

public:
	melodyInput()
	{
		pitch = 0;
		measure = 0;
		meter = 0;
		gesture = 0;
		chord = 0;
	}

	void setPitch(int p, int i = 0)
	{
		
		while (i == 0)
		{
			switch (p)
			{
			case 1:
				cout << "音高為:Do" << endl;
				i++;
				break;
			case 2:
				cout << "音高為:Re" << endl;
				i++;
				break;
			case 3:
				cout << "音高為:Mi" << endl;
				i++;
				break;
			case 4:
				cout << "音高為:Fa" << endl;
				i++;
				break;
			case 5:
				cout << "音高為:So" << endl;
				i++;
				break;
			case 6:
				cout << "音高為:La" << endl;
				i++;
				break;
			case 7:
				cout << "音高為:Si" << endl;
				i++;
				break;
			default:
				cout << "請輸入正確音高: " ;
				cin >> p;
				if (p > 0 && p < 8) i++;
				break;
			}
		}
		pitch = p;
	}

	void setGesture(int g, int i = 0)
	{
		while (i == 0)
		{
			if (g == 4 || g == 8)
			{
				i++;
				break;
			}
			else
			{
				cout << "請重新輸入音型: ";
				cin >> g;
				if (g == 4 || g == 8) i++;
			}
		}
		gesture = g;
	}
	
	void setChord(int c, int i= 0)
	{
		while (i == 0)
		{
			switch (c)
			{
			case 3:
				cout << "和弦設定為:3和弦" << endl;
				i++;
				break;
			case 7:
				cout << "和弦設定為:7和弦" << endl;
				i++;
				break;
			default:
				cout << "請輸入正確和弦: " ;
				cin >> c;
				if (c == 3 || c == 7) i++;
				break;
			}
		}
		chord = c;
	}

	int getPitch()
	{
		return pitch;
	}
	int getMeasure()
	{
		return measure;
	}
	int getMeter()
	{
		return meter;
	}
	int getGesture()
	{
		return gesture;
	}
	int getChord()
	{
		return chord;
	}

	void setPitchArr(int a[8])
	{
		pitchPoint = a;
	}

	void setGeshArr(int a[8])
	{
		gesPoint = a;
	}

	void setChordArr(int a[8])
	{
		chordPoint = a;
	}

	int *getPitchArr()
	{
		return pitchPoint;
	}

	int *getGeshArr()
	{
		return gesPoint;
	}

	int *getChordArr()
	{
		return chordPoint;
	}

	~melodyInput()
	{

	}
};

class harmonyWrite {
private:
	melodyInput melody;
//	check c;
//	fix f;
//	harmonyOutput h;
	int *pitchPoint;
	int *gesPoint;
	int *chordPoint;
	int temp1 = 0, temp2 = 0, temp3 = 0;
	int *melodySp = 0, *melodyAt = 0, *melodyTn = 0;
	int temp[3] = {};

	int pitchArr[8] = {};
	int gesArr[8] = {};
	int chordArr[8] = {};
	

public:
	harmonyWrite()
	{
		pitchPoint = melody.getPitchArr();
		gesPoint = melody.getGeshArr();
		chordPoint = melody.getChordArr();
	}

	void setMelody()
	{
		srand(time(NULL));
		for (int i = 0; i < 8; i++)
		{
			if (chordArr[i] == 3)
			{
				(*(pitchPoint + i) + 2) > 7 ? (temp1 = *(pitchPoint + i) - 7) : temp1 = (*pitchPoint + i);
				(*(pitchPoint + i) + 4) > 7 ? (temp2 = *(pitchPoint + i) - 7) : temp2 = (*pitchPoint + i);
			}
			else if (chordArr[i] == 7)
			{
				(*(pitchPoint + i) + 2) > 7 ? (temp1 = *(pitchPoint + i) - 7) : temp1 = (*pitchPoint + i);
				(*(pitchPoint + i) + 4) > 7 ? (temp2 = *(pitchPoint + i) - 7) : temp2 = (*pitchPoint + i);
				(*(pitchPoint + i) + 6) > 7 ? (temp3 = *(pitchPoint + i) - 7) : temp3 = (*pitchPoint + i);
			}
			temp[0] = temp1;
			temp[1] = temp2;
			temp[2] = temp3;
			*(melodySp + i) = temp[rand() % 3];
			*(melodyAt + i) = temp[rand() % 3];
			*(melodyTn + i) = temp[rand() % 3];
		}

		cout << "Soprano:  ";
		for (int i = 0; i < 8; i++)
		{
			cout << *(melodySp + i) << " ";
		}
		cout << *(melodySp + 7) << endl;
		
		cout << "Alto:     ";
		for (int i = 0; i < 8; i++)
		{
			cout << *(melodyAt + i) << " ";
		}
		cout << *(melodyAt + 7) << endl;

		cout << "Tenor:    ";
		for (int i = 0; i < 8; i++)
		{
			cout << *(melodyTn + i) << " ";
		}
		cout << *(melodyTn + 7) << endl;
	}

	bool judgeFixOrNot()
	{
		
	}
	void writeWithPitchRange()
	{

	}
	void check()
	{
//		if (c.returnCheck()==true)
		{
//			h.print();
		}
//		else
		{
			
		}
	}

	~harmonyWrite()
	{

	}
};

class check {
private:
	harmonyWrite harmonyWrite;

public:
	check()
	{

	}
	
	void setHarmony()
	{
		
	}
	bool judgeDirection()
	{

	}
	bool judgeParallel()
	{

	}
	bool returnCheck()
	{
		if (judgeDirection() == true && judgeParallel() == true)
		{
			return true;
		}
		else return false;
	}
	~check()
	{

	}

};

class fix {
private:
	check check;
	harmonyWrite harmonyWrite;

public:
	fix()
	{

	}


	void fixHarmony()
	{

	}
	bool checkCopy()
	{

	}

	~fix()
	{

	}
};

class harmonyOutput {
private:
	check c;

public:
	harmonyOutput()
	{

	}

	void setCheck(check &c2)
	{
		c = c2;
	}
	check getCheck()
	{
		return c;
	}
	void print()
	{

	}

	~harmonyOutput()
	{

	}
};