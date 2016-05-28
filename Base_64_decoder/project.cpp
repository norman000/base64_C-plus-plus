#include <iostream>
#include <fstream>

using namespace std;

char arr[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

char back(int length) {
    return arr[length];
}

void code(char *file1, char *file2) {

    ifstream in(file1, ios_base::binary);
    if (!in.is_open()) {
        cout << "Can not open file" << endl;
        return;
    }

    ofstream out(file2, ios_base::binary);
    if (!out.is_open()) {
        cout << "Can not open file" << endl;
        return;
    }

    int c = 0;
    char arr1[3];
    char arr2[4];
    while (in.peek() != EOF) {
        in.read(arr1, 3);
        c = in.gcount();

        int i1 = 0, i2 = 0, i3 = 0;
        int j1 = 0, j2 = 0, j3 = 0, j4 = 0;

        // i1, i2, i3
        i1 = arr1[0];
        if (c > 1)
            i2 = arr1[1];
        if (c > 2)
            i3 = arr1[2];

        // j1, j2, j3, j4
        j1 = i1 >> 2;
        j2 = (((i1 << 4) & 48) | (i2 >> 4));
        j3 = (((i2 << 2) & 60) | (i3 >> 6));
        j4 = i3 & 63;

        arr2[0] = back(j1);
        arr2[1] = back(j2);
        if (c > 1)
            arr2[2] = back(j3);
        else
            arr2[2] = '=';

        if (c > 2)
            arr2[3] = back(j4);
        else
            arr2[3] = '=';
        out.write(arr2, 4);

        arr1[0] = arr1[1] = arr1[2] = 0;
    }
    in.close();
    out.close();
}


int main() {

    char file1[256];
    char file2[256];
    cout << "Enter name of file you want to code: " << endl;
    cin >> file1;
    cout << "Enter name of file where to code: " << endl;
    cin >> file2;
    code(file1, file2);

    cout << "Done!\n\n";

    system("PAUSE");
    return 0;
}
