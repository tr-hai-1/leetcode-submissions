import pandas as pd

def combine_two_tables(person: pd.DataFrame, address: pd.DataFrame) -> pd.DataFrame:
  result = person.merge(address, on = 'personId', how = 'left')
  result = result[['firstName', 'lastName', 'city', 'state']]
  return result
    