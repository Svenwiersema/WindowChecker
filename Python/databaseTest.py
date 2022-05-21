# Importing module
import mysql.connector
 
# Creating connection object
mydb = mysql.connector.connect(
    host = "localhost",
    user = "Ramen",
    password = "Ramen"
)

cursor = mydb.cursor()

cursor.execute("SELECT * FROM ramen.ramen")
 
# Printing the connection object
for x in cursor:
    print("ID: " + str(x[0]))
    if x[1] == 1:
        print("open")
    else:
        print("closed")
