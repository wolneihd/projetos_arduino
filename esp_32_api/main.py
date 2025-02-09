from flask import Flask, jsonify, request
from flask_cors import CORS
from datetime import datetime

app = Flask(__name__)
CORS(app)

# Rota para enviar dados via GET
@app.route('/', methods=['GET'])
def get_data():
    data = {
        "nome": "Wolnei",
        "idade": 34
    }
    return jsonify(data)     

# Rota para receber dados via POST
@app.route('/', methods=['POST'])
def post_data():
    try:
        dados = request.get_json() 

        if not dados:
            return jsonify({'erro': 'Nenhum dado enviado'}), 400

        status = dados.get('status')

        if not status:
            return jsonify({'erro': 'Campos obrigatórios: status'}), 400

        hora_atual = datetime.now().strftime("%d/%m/%Y, %H:%M:%S")
        feedback = {
            'status': status,
            'datetime': hora_atual            
        }
        print(feedback)

        return jsonify({'mensagem': 'Feedback recebido', 'feedback': feedback}), 201

    except Exception as e:
        print(e)
        return jsonify({'erro': str(e)}), 500

app.run(port=5000,host="0.0.0.0",debug=True)