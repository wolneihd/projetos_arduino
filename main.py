"""
    Foi utilizado como referência o código da página:
    https://blog.eletrogate.com/como-conectar-o-arduino-com-o-python/
"""

from tkinter import *
import serial
import threading

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

    def ligar(self):
        print("Ligar")
        self.arduino.send_command('l')

    def desligar(self):
        print("Desligar")
        self.arduino.send_command('d')

# Classe principal da interface
class MainWindow(Func):
    def __init__(self, arduino):
        super().__init__(arduino)
        self.root = Tk()
        self.frame()
        self.root.mainloop()

    def frame(self):
        self.root.title("Liga/Desliga LED")
        self.root.geometry("400x300")
        self.root.resizable(True, False)

        self.btnligar = Button(self.root, text='Ligar', font=('Verdana', 10, 'bold'), command=self.ligar)
        self.btnligar.place(relx=.45, rely=.2)

        self.btndesligar = Button(self.root, text='Desligar', font=('Verdana', 10, 'bold'), command=self.desligar)
        self.btndesligar.place(relx=.45, rely=.4)

# Cria o objeto Arduino
arduino = Arduino()

# Inicia a interface gráfica
MainWindow(arduino)
