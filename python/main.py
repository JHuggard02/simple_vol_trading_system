import pricer

S = 100     # Spot
K = 100     # Strike
T = 1       # Time to maturity
r = 0.05    # Risk-free rate
sigma = 0.2 # Volatility

call_price = pricer.black_scholes_price(S, K, T, r, sigma, True)
put_price = pricer.black_scholes_price(S, K, T, r, sigma, False)

print(f"Call: {call_price:.4f}, Put: {put_price:.4f}")
