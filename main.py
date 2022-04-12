from threading import *
import time


def show():
    print('this is a child thread')


t = Thread(target=show())
t.start()

print('this is a parent thread')


class MyThread(Thread):
    def run(self):
        for i in range(5):
            print('\nThis is a child class')


t = MyThread()
t.start()
for i in range(5):
    print("\nThis is a main class")


class Demo:
    def show(self):
        for i in range(3):
            print('this is a child thread')


obj = Demo()
t = Thread(target=obj.show())
t.start()
for i in range(3):
    print("this is the parent thread")


# break

class Demo:
    def num(self):
        for i in range(1, 6):
            print("the number is", i)


    def double(self):
        for i in range(1, 6):
            print("the double of the number is", 2 * i)


    def square(self):
        for i in range(1, 6):
            print("the square of the number is", i * i)



obj = Demo()
t1 = Thread(target=obj.num)
t2 = Thread(target=obj.double)
t3 = Thread(target=obj.square)

t1.start()
time.sleep(0.2)
t2.start()
time.sleep(0.2)
t3.start()

t1.join()
t2.join()
t3.join()

print("this is the parent thread")
