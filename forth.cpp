// forth.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include "pch.h"
//#include "pitch.h"
#include "pitch2.h"
#include <iostream>
using namespace std;

int main()
{
	melodyInput melodyInput;
	harmonyOutput harmonyOutput;

	//2 4 3 | 3 8 7 5 | 1 8 3 2 | 3 4 7

	int pitch = 0, gesture = 0;
	int chord = 0;
	
	int pitchArr[8] = {};
	int gesArr[8] = {};
	int chordArr[8] = {};
	
	int k = 0;
	for (int i = 0; i < 1; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			cout << "請輸入音高(1為Do,2為Re,3為Mi,4為Fa,5為So,6為La,7為Si)、音型(4分音符 or 8分音符)、和弦(3和弦 or 7和弦)" << endl;
			cin >> pitch >> gesture >> chord;
			melodyInput.setPitch(pitch);
			melodyInput.setGesture(gesture);
			melodyInput.setChord(chord);

			pitchArr[k] = melodyInput.getPitch();
			gesArr[k] = melodyInput.getGesture();
			chordArr[k] = melodyInput.getChord();
			k++;

			if (melodyInput.getGesture() == 8)
			{
				cout << "請輸入該拍分的另一個音高" << endl;
				cin >> pitch;
				melodyInput.setPitch(pitch);

				pitchArr[k] = melodyInput.getPitch();
				gesArr[k] = melodyInput.getGesture();
				chordArr[k] = melodyInput.getChord();

				k++;
			}
			else
			{
				pitchArr[k] = 0;
				gesArr[k] = 0;
				chordArr[k] = 0;

				k++;
			}
		}
	}

	//harmonyOutput.print();

	cout << "pitch:    ";
	for (int i = 0; i < 7; i++)
	{
		cout << pitchArr[i] << " ";
	}
	cout << pitchArr[7] << endl;
	

	cout << "gesture:  ";
	for (int i = 0; i < 7; i++)
	{
		cout << gesArr[i] << " ";
	}
	cout << gesArr[7] << endl;
	
	
	cout << "chord:    ";
	for (int i = 0; i < 7; i++)
	{
		cout << chordArr[i] << " ";
	}
	cout << chordArr[7] << endl;

	melodyInput.setPitchArr(pitchArr);
	melodyInput.setGeshArr(gesArr);
	melodyInput.setChordArr(chordArr);

	
	harmonyWrite harmony;
	harmony.setMelody();

	return 0;
}
