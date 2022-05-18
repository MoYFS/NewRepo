import tushare as ts
import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
pro = ts.pro_api('f5ac16fe59a0bbc684d5623f539e85345e6789f40d8ad4b68d5b4574')
df = pro.daily(ts_code='600519.SH', start_date='20180701', end_date='20211220')
df.to_csv('d:\\1.csv')
print(df.head(10))
sz=df.sort_index(axis=0, ascending=True)
sz_return=sz[['pct_chg']]
train=sz_return[0:400]
test=sz_return[401:]
plt.figure(figsize=(10,5))
train['pct_chg'].plot()
plt.legend(loc='best')
plt.show()
plt.figure(figsize=(10,5))
test['pct_chg'].plot(c='r')
plt.legend(loc='best')
plt.show()
train.index =pd.to_datetime(train.index)
test.index =pd.to_datetime(test.index)
dd= np.asarray(train.pct_chg)
y_hat = test.copy()
y_hat['naive'] = dd[len(dd)-1]
plt.figure(figsize=(12,8))
plt.plot(train.index, train['pct_chg'], label='Train')
plt.plot(test.index,test['pct_chg'], label='Test')
plt.plot(y_hat.index,y_hat['naive'], label='Naive Forecast')
plt.legend(loc='best')
plt.title("Naive Forecast")
plt.show()
from sklearn.metrics import mean_squared_error
from math import sqrt
rms = sqrt(mean_squared_error(test.pct_chg, y_hat.naive))
print(rms)
#Simple Average
y_hat_avg = test.copy()
y_hat_avg['avg_forecast'] = train['pct_chg'].mean()
plt.figure(figsize=(12,8))
plt.plot(train['pct_chg'], label='Train')
plt.plot(test['pct_chg'], label='Test')
plt.plot(y_hat_avg['avg_forecast'], label='Average Forecast')
plt.legend(loc='best')
plt.show()
rms = sqrt(mean_squared_error(test.pct_chg, y_hat_avg.avg_forecast))
print(rms)
#Moving Average
y_hat_avg = test.copy()
y_hat_avg['moving_avg_forecast'] = train['pct_chg'].rolling(5).mean().iloc[-1]
plt.figure(figsize=(12,8))
plt.plot(train['pct_chg'], label='Train')
plt.plot(test['pct_chg'], label='Test')
plt.plot(y_hat_avg['moving_avg_forecast'], label='Moving Average Forecast')
plt.legend(loc='best')
plt.show()
rms = sqrt(mean_squared_error(test.pct_chg, y_hat_avg.moving_avg_forecast))
print(rms)
#Simple Average
y_hat_avg = test.copy()
y_hat_avg['avg_forecast'] = train['pct_chg'].mean()
plt.figure(figsize=(12,8))
plt.plot(train['pct_chg'], label='Train')
plt.plot(test['pct_chg'], label='Test')
plt.plot(y_hat_avg['avg_forecast'], label='Average Forecast')
plt.legend(loc='best')
plt.show()
rms = sqrt(mean_squared_error(test.pct_chg, y_hat_avg.avg_forecast))
print(rms)
#Moving Average
y_hat_avg = test.copy()
y_hat_avg['moving_avg_forecast'] = train['pct_chg'].rolling(5).mean().iloc[-1]
plt.figure(figsize=(12,8))
plt.plot(train['pct_chg'], label='Train')
plt.plot(test['pct_chg'], label='Test')
plt.plot(y_hat_avg['moving_avg_forecast'], label='Moving Average Forecast')
plt.legend(loc='best')
plt.show()
rms = sqrt(mean_squared_error(test.pct_chg, y_hat_avg.moving_avg_forecast))
print(rms)

