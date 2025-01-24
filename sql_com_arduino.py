from tkinter import *
import serial
import mysql.connector
from dotenv import load_dotenv
import os
import datetime

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
    
    def receber_comando(self):
        if self.connected:
            msg = self.arduino.readline()
            self.arduino.flush() 
            print('Mensagem serial recebica: ', msg)

# Classe para comunicação com o Banco de Dados
class Repositorio:
    def __init__(self):
        print('Classe "Repositorio" iniciada...')

    def conectar(self):
        try:
            load_dotenv()

            # Acessa as variáveis de ambiente
            self.db_user = os.getenv('BD_USER')
            self.db_password = os.getenv('BD_PASSWORD')
            self.db_port = os.getenv('BD_PORT')
            self.db_host = os.getenv('BD_HOST')
            self.db_database = os.getenv('BD_DATABASE')

            # configurações do BD como um dicionário
            config = {
                'host': self.db_host,
                'port': self.db_port,
                'user': self.db_user,
                'password': self.db_password,
                'database': self.db_database
            }

            conexao = mysql.connector.connect(**config)
            return conexao

        except Exception as error:
            print('Erro ao conectar ao Banco de Dados: ', error)

    def buscar(self):
        try:
            conexao = self.conectar()
            cursor = conexao.cursor()
            cursor.execute("SELECT * FROM tempos;")
            registros = cursor.fetchall()
            for registro in registros:
                print(registro[0], registro[1])
        except Exception as error:
            print('Erro ao fazer "select" no Banco de Dados: ', error)
        finally:
            conexao.close()

    def inserir(self):
        try:
            conexao = self.conectar()
            cursor = conexao.cursor()
            agora = datetime.datetime.now()
            cursor.execute("INSERT INTO tempos (momento) VALUE (%s);", (agora,))
            conexao.commit()
            print(f'Inserido valor na tabela "tempos": {agora}')
        except Exception as error:
            print('Erro ao fazer "select" no Banco de Dados: ', error)
        finally:
            conexao.close()

class Func():
    def __init__(self):
        self.arduino = Arduino()
        self.bd = Repositorio()
        self.iniciar()

    def iniciar(self):
        while True:
            self.arduino.receber_comando()
            self.bd.inserir()   
            self.bd.buscar()             

iniciar = Func()
