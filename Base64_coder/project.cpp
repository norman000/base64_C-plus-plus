#include <iostream>
#include <fstream>

using namespace std;

void decode(char source[4], char dest[3], int &n) {
    n = 0;
    char src[4];
    for (int i = 0; i < 4; i++) {
        if ('A' <= source[i] && source[i] <= 'Z') {
            src[i] = source[i] - 'A';
            continue;
        }
        if ('a' <= source[i] && source[i] <= 'z') {
            src[i] = source[i] - 'a' + 26;
            continue;
        }
        if ('0' <= source[i] && source[i] <= '9') {
            src[i] = source[i] - '0' + 52;
            continue;
        }
        if (source[i] == '+') {
            src[i] = 62;
            continue;
        }
        if (source[i] == '/') {
            src[i] = 63;
            continue;
        }
        if (source[i] == '=') {
            src[i] = 0;
            n++;
            continue;
        }
    }
    dest[0] = (src[0] << 2) | (src[1] >> 4);
    dest[1] = (src[1] << 4) | (src[2] >> 2);
    dest[2] = (src[2] << 6) | (src[3]);
}

int main() {
    ifstream in("File1.txt", ios_base::binary);
    ofstream out("File2.txt", ios_base::binary);

    while (in.peek() != EOF) {
        char source[4], dest[3];
        in.read(source, 4);
        int n;
        decode(source, dest, n);
        if (n == 2)
            out.write(dest, 1);
        else if (n == 1)
            out.write(dest, 2);
        else out.write(dest, 3);
    }
    out.close();
    in.close();

    system("pause");
    return 0;
}
