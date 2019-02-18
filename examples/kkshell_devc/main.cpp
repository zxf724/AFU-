#include <iostream>
#include <getopt.h>
#include <conio.h>
#include "kkshell.h"
#include "kkring.h"
#include "string.h"

#define TEST_LOG(id, format, ...)\
    printf("client-%d>"format"\r\n", id, ##__VA_ARGS__)


/**
 * 命令行测试程序
 *
 * @param argc   参数个数
 * @param argv   参数列表
 */
void cmd_callback_test(int argc, char* argv[]) {

}
char* sh = "helloword""1232";

int main(int argc, char** argv) {
  int  i;

 char s1[] = "12345678";
 char s2[] = "abcd" ;
	
	strncpy(s1, s2, 3);
	printf(s1);
  printf(s1);
  TEST_LOG(1, "hello");
  // KK_CMD_REGISTER(test, "command test", cmd_callback_test);
  while (1) {

    char buf[100];
    // gets(buf);
    buf[i] = getche();

    if (buf[i] == 0x1B) {
      return 0;
    }
    if (buf[i] == 0x0d) {
      buf[i] = 0;
      printf("get s:%s\r\n", buf);
      i = 0;
    } else {
      i++;
    }

  }
  return 0;
}

