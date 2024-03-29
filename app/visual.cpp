#include "visual.h"

int options() {
    int option;
    cout << "(Note: for exit please enter -1)" << endl;
    cout << "options:" << endl;
    cout << "1. kill" << endl;
    cout << "2. stop" << endl;
    cout << "3. cont" << endl;
    cout << ">> ";
    cin >> option;

    return option;
}

int getPid()
{
    int pid;
    cout << "insert pid:" << endl;
    cout << ">> ";
    cin >> pid;

    return pid;
}

void creatorSign() {
    cout << " --------------------------------" << endl;
	cout << "|Tool:     ioctl-communicator    |" << endl;
	cout << "|Creator:  Noam Afergan          |" << endl;
	cout << "|Version:  V1.0                  |" << endl;
	cout << " --------------------------------" << endl << endl;
}
