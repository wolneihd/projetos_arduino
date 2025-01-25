from tkinter import *
import serial
import os
import time
from tkinter import *

# Classe para comunicação com o Arduino
class Arduino:
    def __init__(self, port='COM6', baudrate=9600):
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
    
    def receber_comando(self):
        if self.connected:
            try: 
                time.sleep(0.01)

                valor = self.arduino.readline()
                self.arduino.flush() 
                valor = valor.decode().strip()
                valor = int(valor)

                GREEN = '\033[32m'
                YELLOW = '\033[33m'
                RED = '\033[31m'
                RESET = '\033[0m'

                os.system("cls")
                if (valor <= 85):
                    print('Mensagem serial recebida: ', GREEN, valor, RESET)
                elif (valor <= 170):
                    print('Mensagem serial recebida: ', YELLOW, valor, RESET)
                else:
                    print('Mensagem serial recebida: ', RED, valor, RESET)

                return valor

            except Exception as error:
                print("Erro ao receber dado do serial!")

# Classe principal da interface
class MainWindow():
    def __init__(self):
        self.contador = 1
        self.arduino = Arduino()
        self.root = Tk()
        self.frame()
        self.atualizar_texto()
        self.root.mainloop()

    def frame(self):
        self.root.title("Monitoramento")
        self.root.geometry("300x200")
        self.root.resizable(True, False)

        self.label = Label(self.root, text='Tela de Monitoramento',bd=3, background='#CCFFCC', font=('consolas',10),borderwidth=2, relief="solid", anchor='nw')
        self.label.place(relx=.05, rely=.05, relwidth=.9,relheight=.43)   

        self.texto = Label(self.root, font=('consolas',25), background='#CCFFCC')
        self.texto.place(relx=.17, rely=.24)   

    def atualizar_texto(self):
        # Atualiza o texto com o valor recebido do Arduino
        try:
            valor = self.arduino.receber_comando()
            if (valor <= 85):
                self.label.configure(bg='#CCFFCC')
                self.texto.configure(text=str(valor), bg='#CCFFCC')
            elif (valor <= 170):
                self.label.configure(bg='#ffffb3')
                self.texto.configure(text=str(valor), bg='#ffffb3')
            else:
                self.label.configure(bg='#ffc299')
                self.texto.configure(text=str(valor), bg='#ffc299')
        except Exception as e:
            self.texto.configure(text=f"Erro: {e}")

        # Agenda a próxima atualização a cada 1000 ms (1 segundo)
        self.root.after(1, self.atualizar_texto)

# Inicia a interface gráfica
MainWindow()