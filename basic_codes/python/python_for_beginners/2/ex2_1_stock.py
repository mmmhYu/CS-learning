name="蟑螂地下";stock_price=19.99;stock_code="003032"
stock_price_daily_growth=1.2;growth_day=7
print(f"公司:{name},股票代码:{stock_code},当前股价:{stock_price}")
print("每日增长系数是%.2f,经过%d天的增长后，股价达到了:%.2f"%(stock_price_daily_growth,growth_day,stock_price*1.2**7))