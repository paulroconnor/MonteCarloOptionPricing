### Monte Carlo Option Pricing

Implementing a Monte Carlo simulation for pricing various types of financial options, including European, Asian, Lookback, and Barrier options. The code is written in C++ and demonstrates the use of stochastic processes to model the behavior of asset prices over time.

Prices are assumed to follow a Geometric Brownian Motion, defined by:

$$ dS_t = \mu S_t \, dt + \sigma S_t \, dW_t $$

where:
- $` S_t `$ is the asset price at time $` t `$
- $` \mu `$ is the drift coefficient (growth rate)
- $` \sigma `$ is the volatility of the asset
- $` W_t `$ is a Wiener process (standard Brownian motion)

The simulation uses the discrete time approximation of the process and price paths follow:

$$ S_{t+\Delta t} = S_t \exp \left( \left( \mu - \frac{\sigma^2}{2} \right) \Delta t + \sigma \sqrt{\Delta t} Z \right) $$

where:
- $` \Delta t `$ is the time step, which is $` \frac{1}{252} `$ assuming 252 trading days in a year
- $` Z `$ is a random variable drawn from a standard normal distribution

The option payoff are calculated as follows:

##### European Options
$$
\text{Call Payoff} = \max(S_T - K, 0)
$$

$$
\text{Put Payoff} = \max(K - S_T, 0)
$$

##### Asian Options

$$
\text{Call Payoff} = \max(\bar{S} - K, 0)
$$

$$
\text{Put Payoff} = \max(K - \bar{S}, 0)
$$

##### Lookback Options
$$
\text{Floating Strike Call Payoff} = \max(S_T - \min(S), 0)
$$

$$
\text{Floating Strike Put Payoff} = \max(\max(S) - S_T, 0)
$$

$$
\text{Fixed Strike Call Payoff} = \max(\max(S) - K, 0)
$$

$$
\text{Fixed Strike Put Payoff} = \max(K - \min(S), 0)
$$


##### Barrier Options

$$
\text{In-Barrier Call Payoff} = \begin{cases}
\max(S_T - K, 0) & \text{if barrier is hit} \\
0 & \text{otherwise}
\end{cases}
$$

$$
\text{In-Barrier Put Payoff} = \begin{cases}
\max(K - S_T, 0) & \text{if barrier is hit} \\
0 & \text{otherwise}
\end{cases}
$$

$$
\text{Out-Barrier Call Payoff} = \begin{cases}
0 & \text{if barrier is hit} \\
\max(S_T - K, 0) & \text{otherwise}
\end{cases}
$$

$$
\text{Out-Barrier Put Payoff} = \begin{cases}
0 & \text{if barrier is hit} \\
\max(K - S_T, 0) & \text{otherwise}
\end{cases}
$$






