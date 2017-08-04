int scan () {
 char ch = ' ';
 while (ch < '0'|| ch > '9') ch = getchar ();
 int x = 0;
 while (ch <= '9' && ch >= '0') x = x*10+ch-'0', ch = getchar ();
 return x;
}