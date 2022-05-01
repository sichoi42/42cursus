#include <term.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

struct termios org_term;
struct termios new_term;

// org_term에 초기 터미널 세팅 저장
void save_input_mode(void)
{
	tcgetattr(STDIN_FILENO, &org_term); // STDIN으로부터 터미널 속성을 받아온다
}

// new_term에 원하는 터미널 속성 설정
void set_input_mode(void)
{
	tcgetattr(STDIN_FILENO, &new_term); // STDIN으로부터 터미널 속성을 받아온다
	new_term.c_lflag &= ~(ICANON | ECHO);  // ICANON, ECHO 속성을 off
	new_term.c_cc[VMIN] = 1;               // 1 바이트씩 처리
	new_term.c_cc[VTIME] = 0;              // 시간은 설정하지 않음
	tcsetattr(STDIN_FILENO, TCSANOW, &new_term); // 변경된 속성의 터미널을 STDIN에 바로 적용
}

// 기존의 터미널 세팅으로 다시 변경
void reset_input_mode(void)
{
	tcsetattr(STDIN_FILENO, TCSANOW, &org_term);  // STDIN에 기존의 터미널 속성을 바로 적용
}

int main(void)
{
	int ch;
	int	idx;

	// save_input_mode();       // 터미널 세팅 저장
	set_input_mode();        // 터미널 세팅 변경
	ch = 0;
	idx = -1;
	while (read(0, &ch, sizeof(int)) > 0)
	{
		if (ch == 4 || ch == 3)// ctrl d or ctrl c
		{
			if (ch == 3)
				break ;
			if (idx == -1)
				exit(0);
		}
		else if (ch == 127)//backspace
		{
			if (idx >= 0)
			{
				write(0, "\b \b", 3);
				--idx;
			}
		}
		else if (ch == '\n')
			break ;
		else
		{
			write(0, &ch, sizeof(int));
			++idx;
		}
		ch = 0;
	}
	// reset_input_mode();      // 터미널 세팅 초기화
	return (0);
}
