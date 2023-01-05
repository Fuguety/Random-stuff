#password cracker (bruteforce)

answer = input('Password: ')


# conditios to activate the loop
hehe = ''
password = ord('0')
password1 = ord('0')
password2 = ''
password3 = 47
password4 = ''
password5 = ord('0')
password6 = ''

# conditions to get out ///////////////////////////
breach = 0
out1 = 0
out = 0
out3 = 0
out4 = 0


# PS: IT CAN STILL BE OPTIMIZED, work in progres :)


while out4 <= 74:   # X000 character
    out3 = 0
    password3 = 47
    passord5 = password5 + 1

    while out3 <= 74:   # 0X00 character
        out = 0
        password1 = 47
        password3 = password3 + 1

        while out <= 74:    #00X0 character
            out1 = 0
            password = 47
            password1 = password1 + 1

            while out1 <= 73: #000X character
                password = password + 1
                hehe = password6 + password4 + password2 + chr(password)
                print(hehe)     #print the answer

                if hehe == answer:
                    break
                
                out1 = out1 + 1

            if hehe == answer:
                break

            
            password2 = chr(password1)



            out = out + 1


        if hehe == answer:
            break

        password4 = chr(password3)


        out3 = out3 + 1 
    
    if hehe == answer:
        break

    password6 = chr(passord5)

    out4 = out4 + 1


