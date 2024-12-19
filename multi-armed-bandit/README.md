# Multi-armed Bandit

```bash
$ python3 -m venv venv --clear
$ . venv/bin/activate
$ pip3 install -r requirements.txt
```

## Run

```bash
$ make run
```

## Details

I've implemented five different MAB strategies that showcase different approaches to the exploration-exploitation tradeoff:

1. Pure Exploration:
   - Completely random arm selection
   - Always explores, never exploits

2. Pure Exploitation:
   - Always chooses the arm with the highest observed mean reward
   - No exploration after initial sampling
   - Can get stuck on suboptimal arms

3. epsilon-greedy:
   - Balances exploration and exploitation
   - Explores randomly with probability e
   - Exploits best known arm with probability 1-e
   - Simple but effective

4. Upper Confidence Bound (UCB):
   - Automatically balances exploration/exploitation
   - More sophisticated than ε-greedy
   - No hyperparameters to tune (unlike epsilon-greedy)

The core idea ois to estimate not just the expected reward of each arm,
but also how uncertain we are about that estimate. It follows the
principle of "optimism in the face of uncertainty".

UCB Value = Empirical Mean + Exploration Bonus

```
UCB_i(t) = X̄_i + sqrt(2 * log(t) / n_i)
```

Where:

- X̄_i is the empirical mean reward of arm i
- t is the current time step (total number of pulls)
- n_i is the number of times arm i has been pulled
- The exploration bonus is sqrt(2 * log(t) / n_i)

Exploration Bonus:

- Decreases as an arm is pulled more (n_i increases)
- Increases logarithmically with total time (log(t))
- Ensures all arms are tried eventually

Balance Mechanism:

- New/less-pulled arms: High exploration bonus → more likely to be tried
- Well-understood arms: Low exploration bonus → selected based on empirical performance
- Poor-performing arms: Eventually ignored as empirical mean becomes reliables

5. Thompson Sampling:
   - Bayesian approach using Beta distributions
   - Naturally balances exploration/exploitation
   - Often performs best in practice
   - More computationally intensive

How it works:

- For each arm, maintains a probability distribution over each arm's expected reward
- Uses Beta distribution for Bernoulli bandits (rewards are 0 or 1)
- Samples from these distributions to make decisions
- Sample θᵢ from Beta(αᵢ, βᵢ) for each arm and chooses arm with highest sampled value
- Update parameters based on reward

Why Beta Distribution?

- Shape determined by α (successes) and β (failures)
- Mean = α/(α+β)
- Gets narrower with more data
- Natural representation of uncertainty
