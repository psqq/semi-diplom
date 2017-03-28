import subprocess
from tkinter import filedialog as tkFileDialog
from tkinter import *

def remove_empty_lines(s):
    return "\n".join(list(filter(bool, s.splitlines()))) + "\n"

def recompute(e):
    global tb_g1, tb_g2, s1, s2, pi_g1, pi_g2, img_g1, img_g2
    global fr_g1_img_s1, fr_g2_img_s2
    s1 = tb_g1.get('1.0', 'end')
    s2 = tb_g2.get('1.0', 'end')
    s1 = remove_empty_lines(s1)
    s2 = remove_empty_lines(s2)
    with open("g1.txt", "w") as f:
        f.write(s1)
    with open("g2.txt", "w") as f:
        f.write(s2)
    subprocess.call("make run_bin_tests_2", shell=True)
    pi_g1 = PhotoImage(file='g1.png')
    img_g1 = Label(fr_g1_img_s1, image=pi_g1)
    img_g1.grid(row=2, column=2)
    pi_g2 = PhotoImage(file='g2.png')
    img_g2 = Label(fr_g2_img_s2, image=pi_g2)
    img_g2.grid(row=2, column=2)
    global full_output, log_txt
    full_output.delete('1.0', 'end')
    with open("log.txt", "r") as f:
        log_txt = f.read()
    full_output.insert('1.0', log_txt)


root = Tk()

with open("g1.txt", "r") as f:
    s1 = f.read()
with open("g2.txt", "r") as f:
    s2 = f.read()
with open("log.txt", "r") as f:
    log_txt = f.read()
s1 = remove_empty_lines(s1)
s2 = remove_empty_lines(s2)

fr_g1_img_s1 = Frame(root)
lbl_g1 = Label(fr_g1_img_s1, text='Граф g1:')
lbl_g1.grid(row=1, column=1)
tb_g1 = Text(fr_g1_img_s1, font='Monospace', width=20, height=10)
tb_g1.insert(INSERT, s1)
tb_g1.grid(row=2, column=1)
lbl_img_g1 = Label(fr_g1_img_s1, text='Изображение g1:')
lbl_img_g1.grid(row=1, column=2)
pi_g1 = PhotoImage(file='g1.png')
img_g1 = Label(fr_g1_img_s1, image=pi_g1)
img_g1.grid(row=2, column=2)

fr_g2_img_s2 = Frame(root)
lbl_g2 = Label(fr_g2_img_s2, text='Граф g2:')
lbl_g2.grid(row=1, column=1)
tb_g2 = Text(fr_g2_img_s2, font='Monospace 10', width=20, height=10)
tb_g2.insert(INSERT, s2)
tb_g2.grid(row=2, column=1)
lbl_img_g2 = Label(fr_g2_img_s2, text='Изображение g2:')
lbl_img_g2.grid(row=1, column=2)
pi_g2 = PhotoImage(file='g2.png')
img_g2 = Label(fr_g2_img_s2, image=pi_g2)
img_g2.grid(row=2, column=2)

all_frame = Frame(root)
full_output = Text(all_frame, font='Monospace 10', width=60, height=40)
full_output.insert(INSERT, log_txt)
scrollbar = Scrollbar(all_frame)
scrollbar['command'] = full_output.yview
full_output['yscrollcommand'] = scrollbar.set
full_output.pack(side='left', fill="both", expand=True)
scrollbar.pack(side='right', fill="both", expand=True)

btn = Button(root, text='Пересчитать')
btn.bind("<Button-1>", recompute)

fr_g1_img_s1.grid(row=1, column=1)
fr_g2_img_s2.grid(row=2, column=1)
all_frame.grid(row=1, column=2, rowspan=2)
btn.grid(row=3, column=1)

root.mainloop()
