from mlxtend.frequent_patterns import apriori, association_rules
from mlxtend.preprocessing import TransactionEncoder
import pandas as pd

# Dataset 1: Market Basket
dataset1 = [['milk', 'bread', 'nuts', 'apple'],
            ['milk', 'bread', 'apple'],
            ['milk', 'bread'],
            ['milk', 'bread', 'apple'],
            ['milk', 'bread', 'apple', 'banana']]

# Dataset 2: Another basket dataset
dataset2 = [['beer', 'nuts'],
            ['beer', 'cheese'],
            ['beer', 'nuts', 'cheese'],
            ['beer', 'nuts'],
            ['nuts', 'cheese']]

def run_apriori(dataset, min_support, min_conf):
    te = TransactionEncoder()
    df = pd.DataFrame(te.fit(dataset).transform(dataset), columns=te.columns_)
    frequent_itemsets = apriori(df, min_support=min_support, use_colnames=True)
    rules = association_rules(frequent_itemsets, metric='confidence', min_threshold=min_conf)
    print(f"\nFrequent Itemsets:\n{frequent_itemsets}")
    print(f"\nAssociation Rules:\n{rules[['antecedents', 'consequents', 'support', 'confidence', 'lift']]}")
    return rules

# Run for both sets of parameters
print("Dataset 1: Support=0.5, Confidence=0.75")
run_apriori(dataset1, 0.5, 0.75)

print("\nDataset 1: Support=0.6, Confidence=0.6")
run_apriori(dataset1, 0.6, 0.6)

print("\nDataset 2: Support=0.5, Confidence=0.75")
run_apriori(dataset2, 0.5, 0.75)

print("\nDataset 2: Support=0.6, Confidence=0.6")
run_apriori(dataset2, 0.6, 0.6)
