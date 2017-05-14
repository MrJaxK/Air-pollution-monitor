import requests
def get_data(API):
    response=requests.get(API)
    print(response.status_code)
    #print (response.json())
    json_data=response.json()       #json_data 是listc
    return json_data

def text_create(name, msg):
    #python_path = 'C://文档//Python'
    full_path =name + '.txt'
    #print(full_path)
    file = open(full_path,'w')
    file.write(msg)
    file.close()
    print('Done')

def deal_with_data(data):                      #location为文件位置
    i=0
    str_contains=str(data)
    new_string=str_contains[:]
    while True:
        i=new_string.find('}',i)
        new_string=new_string[:i+2]+"\n"+new_string[i+2:]
        #print(i)
        if i==-1:
            break
        i=i+5
    return(new_string)

city_API='http://www.pm25.in/api/querys.json?'
token='token=5j1znBVAsnSf5xQyNQyq'
data1=get_data(city_API+token)
#print (type(data1))
for city in data1['cities']:
    dic={"PM2.5_":'http://www.pm25.in/api/querys/pm2_5.json?city='+city+'&token=5j1znBVAsnSf5xQyNQyq',
    "PM10_":'http://www.pm25.in/api/querys/pm10.json?city='+city+'&token=5j1znBVAsnSf5xQyNQyq',
    "CO_":"http://www.pm25.in/api/querys/co.json?city="+city+'&token=5j1znBVAsnSf5xQyNQyq',
    "NO2_":"http://www.pm25.in/api/querys/no2.json?city="+city+'&token=5j1znBVAsnSf5xQyNQyq',
    "SO2_":"http://www.pm25.in/api/querys/so2.json?city="+city+'&token=5j1znBVAsnSf5xQyNQyq',
    "03_":"http://www.pm25.in/api/querys/o3.json?city="+city+'&token=5j1znBVAsnSf5xQyNQyq',
    }
    #try:
    for item in dic:
        API=dic[item]
        data=get_data(API)
        #print(type(data))                           # 原始数据
        #name2=item+data[0]['time_point'][11:13]+'.'+data[0]['time_point'][14:16]+'original'
        #text_create(name2,str(data))
        try:
            name=city+'_'+item+data[0]['time_point'][11:13]+'.'+data[0]['time_point'][14:16]
            new_data=deal_with_data(data)

            #print(type(new_data))                        #修改后的数据
            text_create(name,new_data)
        except:
            continue
