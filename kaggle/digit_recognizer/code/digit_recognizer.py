# -*- coding: utf-8 -*-
"""
Created on Thu Aug 17 17:47:52 2017

@author: Administrator
"""

import pandas as pd
import numpy as np
from sklearn.neighbors import KNeighborsClassifier

train_df = pd.read_csv('../data/train.csv')
test_df = pd.read_csv('../data/test.csv')

threshold = 50
X_train = train_df.drop("label", axis=1)
X_train[X_train < threshold] = 0
X_train[X_train >= threshold] = 1

Y_train = train_df["label"]

X_test  = test_df.copy()
X_test[X_test < threshold] = 0
X_test[X_test >= threshold] = 1

knn = KNeighborsClassifier(n_neighbors = 3)
knn.fit(X_train, Y_train)
Y_pred = knn.predict(X_test)

submission = pd.DataFrame({
        "ImageId":  pd.Series(np.arange(1, X_test.shape[0])),
        "Label": Y_pred
    })
# submission.to_csv('../output/submission.csv', index=False)