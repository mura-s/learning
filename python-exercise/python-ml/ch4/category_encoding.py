import pandas as pd

df = pd.DataFrame([
    ['green', 'M',  10.1, 'class1'],
    ['red',   'L',  13.5, 'class2'],
    ['blue',  'XL', 15.3, 'class1']
])
df.columns = ['color', 'size', 'price', 'classlabel']

size_mapping = {'XL': 3, 'L': 2, 'M': 1}
df['size'] = df['size'].map(size_mapping)

from sklearn.preprocessing import LabelEncoder

class_le = LabelEncoder()
df['classlabel'] = class_le.fit_transform(df['classlabel'].values)

from sklearn.preprocessing import OneHotEncoder

X = df[['color', 'size', 'price']].values
color_le = LabelEncoder()
X[:, 0] = color_le.fit_transform(X[:, 0])

ohe = OneHotEncoder(categorical_features=[0])
print(ohe.fit_transform(X).toarray())
