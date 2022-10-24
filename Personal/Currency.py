import requests
import time

url = "https://api.apilayer.com/exchangerates_data/convert?to=HKD&from=GBP&amount=10000"

payload = {}
headers= {
  "apikey": "tiyERJ7OAXNhB6KSVg2mm7POiWr73S7J"
}

response = requests.request("GET", url, headers=headers, data = payload)

status_code = response.status_code
result = response.text

o = 0

while o == 0:
    print(result)
    time.sleep(1)