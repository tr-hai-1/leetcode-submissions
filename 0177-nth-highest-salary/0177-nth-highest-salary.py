import pandas as pd

def nth_highest_salary(employee: pd.DataFrame, N: int) -> pd.DataFrame:
  unique = employee['salary'].drop_duplicates()
  sorted_salaries = unique.sort_values(ascending = False)
  if N > len(sorted_salaries) or N < 1:
    return pd.DataFrame({f'getNthHighestSalary({N})': [None]})
  nth_highest = sorted_salaries.iloc[N - 1]
  return pd.DataFrame({f'getNthHighestSalary({N})': [nth_highest]})