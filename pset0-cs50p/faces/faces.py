msg = input("")
if ":)" in msg:
    msg = msg.replace(":)","☺️")
elif ":(" in msg:
    msg = msg.replace(":(","☹️")

print(msg)