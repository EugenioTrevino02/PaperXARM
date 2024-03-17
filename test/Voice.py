import speech_recognition as sr
import pyttsx3 
 
# Initialize the recognizer 
r = sr.Recognizer() 
bandera = 0
b2 = 0

def record_text():
    while(1):   
        try:
            with sr.Microphone() as source2:
                r.adjust_for_ambient_noise(source2, duration=0.2)
             
                #listens for the user's input 
                audio2 = r.listen(source2)
                
                # Using google to recognize audio
                MyText = r.recognize_google(audio2, language="es-ES")
                return MyText
           
             
        except sr.RequestError as e:
            print("Could not request results; {0}".format(e))
            
        except sr.UnknownValueError:
            print("error occurred")
    return 

def output_text(text, bandera):  
    if (bandera == 1):
        print("pase")
        f = open("output.txt", "a")
        if (text == ("esfera")):
            f.write("1")
            f.write("\n")
        elif (text == ("cubo")):
            f.write("2")
            f.write("\n")
        elif (text == ("cuboide")):
            f.write("3")
            f.write("\n")
        elif (text == ("cilindro")):
            f.write("4")
            f.write("\n")
        elif (text == ("prisma hexagonal")):
            f.write("5")
            f.write("\n")
        elif (text == "prisma triangular"):
            f.write("6")
            f.write("\n")
            print("Ya comenzo el programa")
        elif (text == ("cono")):
            f.write("7")
            f.write("\n")
        elif (text == ("piramide cuadrada")):
            f.write("8")
            f.write("\n")
        elif (text == ("piramide triangular")):
            f.write("9")
            f.write("\n")
  
        
        f.close()

    print(text)
    

def output_textFlag(text): 
    if (text == "comienza"):
        bandera = 1
        print("Bandera enviada")
        f = open("output.txt", "w")
        #f.write(text)
        #f.write("\n")  
        f.close()
        return bandera 
    if (text == "acaba"):
        bandera = 0
        return bandera 

while(1):
    print("Pruebaaaaa")
    text = record_text()
    text = text.lower()
    if b2 != 1:
        bandera = output_textFlag(text) 
        b2 = bandera
    if output_textFlag(text) == 0: 
        b2 = 0 
    output_text(text, b2)

    print("Wrote text")