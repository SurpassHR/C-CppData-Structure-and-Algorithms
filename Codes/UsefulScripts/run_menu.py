import curses
import os

class Menu:
    def __init__(self, title, options, multi_select: bool) -> None:
        self.title = title
        self.options = options
        self.selected_options = [False] * len(self.options)
        self.current_selection = 0
        self.max_option_len = max([len(option) for option in options])
        self.multi_select = multi_select

    def __display(self, stdscr, h, w):
        x_title = 0
        stdscr.addstr(1, x_title, self.title, curses.A_BOLD)

        for idx, option in enumerate(self.options):
            x = 0
            y = h // 10 + idx
            if self.selected_options[idx]:
                display_option = f"[√] {option}"
            else:
                display_option = f"[ ] {option}"

            if idx == self.current_selection:
                if not self.selected_options[idx]:
                    display_option = f"[x] {option}"
                stdscr.attron(curses.color_pair(1))
                stdscr.addstr(y, x, display_option, curses.A_BOLD)
                stdscr.attroff(curses.color_pair(1))
            else:
                stdscr.addstr(y, x, display_option)

    def __multi_select(self, key):
        if key == curses.KEY_UP or key == ord('k'):
            self.current_selection = (self.current_selection - 1) % len(self.options)
        elif key == curses.KEY_DOWN or key == ord('j'):
            self.current_selection = (self.current_selection + 1) % len(self.options)
        elif key == ord(' '):  # 空格键选择或取消选择
            self.selected_options[self.current_selection] = not self.selected_options[self.current_selection]
        elif key == curses.KEY_ENTER or key in [10, 13] or key == ord('q'):  # Enter键确认
            return [self.options[i] for i in range(len(self.options)) if self.selected_options[i]]

    def __single_select(self, key):
        if key == curses.KEY_UP or key == ord('k'):
            self.current_selection = (self.current_selection - 1) % len(self.options)
        elif key == curses.KEY_DOWN or key == ord('j'):
            self.current_selection = (self.current_selection + 1) % len(self.options)
        elif key == curses.KEY_ENTER or key in [10, 13] or key == ord('q') or key == ord(' '):  # Enter键确认
            self.selected_options[self.current_selection] = not self.selected_options[self.current_selection]
            return [self.options[i] for i in range(len(self.options)) if self.selected_options[i]]

    def __menu(self, stdscr):
        h, w = stdscr.getmaxyx()
        curses.curs_set(0)

        while True:
            stdscr.clear()
            self.__display(stdscr, h, w)
            stdscr.refresh()
            key = stdscr.getch()
            ret = []
            if self.multi_select:
                ret = self.__multi_select(key)
            else:
                ret = self.__single_select(key)
            if ret != None:
                return ret

    def run(self):
        return curses.wrapper(self.__menu)

def getFileName():
    return [ excel for excel in os.listdir(os.getcwd()) if '.xls' in excel ]

def main():
    options = getFileName()
    if len(options) == 0:
        print('[ERROR] 当前文件夹下无差异化excel文件')
        input("按回车键退出...")
        exit(-1)
    title = '选择输入文件(多选，空格选中，回车确认，按q退出): '
    menu = Menu(title = title, options = options, multi_select = True)
    selected_file = menu.run()

    options = ['是', '否']
    title = '选择是否生成信号差异化json文件(单选，空格选中，回车确认，按q退出): '
    menu = Menu(title = title, options = options, multi_select = True)
    json_option = menu.run();

    commands = []
    for file in selected_file:
        sub_cmd = ['python lcc_diff_tool.py']
        sub_cmd.append(f'-i {file}')
        if json_option != []:
            sub_cmd.append('-j')
        commands.append(sub_cmd)

    for cmd in commands:
        cmd_str = ' '.join(cmd)
        os.system(cmd_str)

    input("按回车键退出...")
    exit(0)

if __name__ == '__main__':
    main()