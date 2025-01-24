from tkinter import *
import serial

# Classe para comunicação com o Arduino
class Arduino:
    def __init__(self, port='COM5', baudrate=9600):
        self.port = port
        self.baudrate = baudrate
        self.arduino = None
        self.connected = False
        self.connect()

    def connect(self):
        while not self.connected:  # Tenta conectar até ter sucesso
            try:
                self.arduino = serial.Serial(self.port, self.baudrate)
                print('Arduino conectado com sucesso!')
                self.connected = True
            except:
                print('Tentando conectar ao Arduino...')
    
    def send_command(self, cmd):
        if self.connected:
            self.arduino.write(cmd.encode())
            self.arduino.flush()

# Classe de funcionalidades
class Func:
    def __init__(self, arduino):
        self.arduino = arduino

    def ligar_01(self):
        print("Ligar 01")
        self.arduino.send_command('a')

    def ligar_02(self):
        print("Ligar 02")
        self.arduino.send_command('b')

    def desligar(self):
        print("Desligar TODOS")
        self.arduino.send_command('c')

# Classe principal da interface
class MainWindow(Func):
    def __init__(self, arduino):
        super().__init__(arduino)
        self.root = Tk()
        self.frame()
        self.root.mainloop()

    def frame(self):
        self.root.title("Liga/Desliga LED")
        self.root.geometry("300x300")
        self.root.resizable(True, False)

        self.btnligar_01 = Button(self.root, text='Ligar 01', font=('Verdana', 10, 'bold'), 
                               command=self.ligar_01, 
                               borderwidth=3,
                               bg='lightgreen')
        self.btnligar_01.place(relx=.25, rely=.2, relwidth=.4, relheight=.1)

        self.btndesligar_01 = Button(self.root, text='Desligar 01', font=('Verdana', 10, 'bold'), 
                                  command=self.desligar, 
                                  borderwidth=3,
                                  bg='coral')
        self.btndesligar_01.place(relx=.25, rely=.4, relwidth=.4, relheight=.1)

        self.btnligar_02 = Button(self.root, text='Ligar 02', font=('Verdana', 10, 'bold'), 
                               command=self.ligar_02, 
                               borderwidth=3,
                               bg='lightgreen')
        self.btnligar_02.place(relx=.25, rely=.6, relwidth=.4, relheight=.1)

        self.btndesligar_02 = Button(self.root, text='Desligar 02', font=('Verdana', 10, 'bold'), 
                                  command=self.desligar, 
                                  borderwidth=3,
                                  bg='coral')
        self.btndesligar_02.place(relx=.25, rely=.8, relwidth=.4, relheight=.1)

# Cria o objeto Arduino
arduino = Arduino()

# Inicia a interface gráfica
MainWindow(arduino)
