/**
+---------+------------+------------+
|  color  | foreground | background |
|         |    code    |    code    |
+---------+------------+------------+
| black   |     30     |     40     |
| red     |     31     |     41     |
| green   |     32     |     42     |
| yellow  |     33     |     43     |
| blue    |     34     |     44     |
| magenta |     35     |     45     |
| cyan    |     36     |     46     |
| white   |     37     |     47     |
+---------+------------+------------+

printf("\x1b[32m green text on regular background \x1b[0m  \n");
printf("\x1b[32;40m green text on black background \x1b[0m  \n");
printf("\x1b[42m regular text on green background \x1b[0m  \n");
*/


using namespace std;

class Style
{
public:
    static string getBlackColor(string text) {
        return "\x1b[30m" + text + "\x1b[0m";
    } 

    static string getRedColor(string text) {
        return "\x1b[31m" + text + "\x1b[0m";
    } 

    static string getGreenColor(string text) {
        return "\x1b[32m" + text + "\x1b[0m";
    } 

    static string getYellowColor(string text) {
        return "\x1b[33m" + text + "\x1b[0m";
    } 

    static string getBlueColor(string text) {
        return "\x1b[34m" + text + "\x1b[0m";
    } 

    static string getMegentaColor(string text) {
        return "\x1b[35m" + text + "\x1b[0m";
    } 

    static string getCyanColor(string text) {
        return "\x1b[36m" + text + "\x1b[0m";
    } 

    static string getWhiteColor(string text) {
        return "\x1b[37m" + text + "\x1b[0m";
    } 

    static string getBold(string text) {
        return "\x1b[1m" + text + "\x1b[0m";
    }
};