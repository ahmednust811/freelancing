
from smbus import SMBus
addr = 0x44
bus = SMBus(1)
limit =  1
print("Enter the menu:")
print("a : keep led on")
print("b : slow blink led")
print("c : fast blink led")
print("d : keep led off")

while limit == 1:
        menu = input(">>>")
        if(menu == "a"or menu == "b" or menu == "c" or menu == "d"):
            bus.write_byte(addr,ord(menu))
            print(menu)
        else:
                limit = 0
