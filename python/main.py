import pricer

# Use static utility functions
price = pricer.black_scholes_price(S=100, K=100, T=1, r=0.05, sigma=0.2, isCall=True)
print(price)

iv = pricer.iv(S=100, K=100, T=1, r=0.05, initial_sigma=0.2, isCall=True, marketPrice=12)
print(iv)

# Use your C++ model class
# from pricer import BlackScholesMerton

# model = BlackScholesMerton(100, 0.05, 0.2)
# path = model.generate_path(1.0, 100)
# for num in path:
#     print(num)