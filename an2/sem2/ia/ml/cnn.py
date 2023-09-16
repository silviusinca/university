import numpy as np # linear algebra
import pandas as pd # data processing, CSV file I/O (e.g. pd.read_csv)
import os
import tensorflow as tf
import cv2
from tensorflow.keras import layers
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import LabelEncoder, OneHotEncoder
from tensorflow.keras.optimizers import Adam
from tensorflow.keras.preprocessing.image import ImageDataGenerator
from tensorflow.keras.callbacks import EarlyStopping, ReduceLROnPlateau
from tensorflow.keras.utils import to_categorical

# initial, setez path-ul pentru a lua datele (csv-urile si imaginile) necesare modelului; 
dataset_path = "/kaggle/input/unibuc-dhc-2023"

# ma folosesc de pd.read_csv pentru a lua datele din train.csv
train_csv = os.path.join(dataset_path, "train.csv")
train_data = pd.read_csv(train_csv)

# pe urmatoarele linii prelucrez datele in felul urmator: 
# - in image_names si labels(initial) voi avea valorile coloanelor respective din fisierul csv
# - in images si labels voi avea imaginile si etichetele corespunzatoare fisierului
image_names = train_data['Image'].values
labels = train_data['Class'].values

images = []
for image_name in image_names:
    path = os.path.join(dataset_path, "train_images", image_name)
    image = cv2.imread(path)
    images.append(image)

images = np.array(images)
labels = np.array(labels)

# normalizam pixelii imaginile pentru a avea valori cuprinse intre 0 si 1
images = images / 255.0

label_encoder = LabelEncoder()
encoded_labels = label_encoder.fit_transform(labels)
num_classes = 96 # numarul de tipuri de imagini
one_hot_labels = to_categorical(encoded_labels, num_classes)

x_train = images # imaginile pentru antrenat
y_train = one_hot_labels # label-urile potrivite

num_channels = 3 # corespunde numarului de canele de culori(in cazul de fata avem imagini ce au culori RGB) 
image_width, image_height = 64, 64 # latime, inaltime pentru imagini

# aici vom crea modelul CNN (convolutional neural network) folosindu-ne de keras
model = tf.keras.Sequential([
    # adaugam layerele necesare
    layers.Conv2D(filters=32, kernel_size=(3, 3), activation='relu', input_shape=(image_width, image_height, num_channels)),
    layers.MaxPooling2D(pool_size=(2, 2)),
    layers.Conv2D(filters=64, kernel_size=(3, 3), activation='relu'),
    layers.MaxPooling2D(pool_size=(2, 2)),
    layers.Conv2D(filters=128, kernel_size=(3, 3), activation='relu'),
    layers.MaxPooling2D(pool_size=(2, 2)),
    layers.Flatten(), # facem din matrice un vector 
    layers.Dense(units=256, activation='relu'),
    layers.Dense(units=num_classes, activation='softmax')
])

# configuram modelul pentru training
model.compile(optimizer='adam', loss='categorical_crossentropy', metrics=['accuracy'])
batch_size, num_epochs = 64, 10 

datagen = ImageDataGenerator(rotation_range=20, width_shift_range=0.2, height_shift_range=0.2, horizontal_flip=True)
datagen.fit(x_train)

x_train, x_val, y_train, y_val = train_test_split(x_train, y_train, test_size=0.2, random_state=42)

# antrenam modelul 
model.fit(datagen.flow(x_train, y_train, batch_size=batch_size), epochs=num_epochs, validation_data=(x_val, y_val))

# evaluam datele din val.csv pe modelul facut mai sus
# repetam de altfel aceleasi proceduri pentru procesare/preprocesare a datelor
val_csv = os.path.join(dataset_path, "val.csv")
val_data = pd.read_csv(val_csv)

val_image_names = val_data['Image'].values
val_labels = val_data['Class'].values

val_images = []
for image_name in val_image_names:
    path = os.path.join(dataset_path, "val_images", image_name)
    image = cv2.imread(path)
    val_images.append(image)

val_images = np.array(val_images)
val_labels = np.array(val_labels)

val_images = val_images / 255.0

label_encoder = LabelEncoder()
encoded_val_labels = label_encoder.fit_transform(val_labels)
one_hot_val_labels = to_categorical(val_labels, num_classes)

x_test = val_images
y_test = one_hot_val_labels

test_loss, test_accuracy = model.evaluate(x_test, y_test)
print('Test Loss:', test_loss)
print('Test Accuracy:', test_accuracy)

# repetam procesul de preprocesare + la final vom crea un submission_file folosindu-ne de un DataFrame din pandas, iar apoi de metoda to_csv pentr a-l crea efectiv

test_csv = os.path.join(dataset_path, "test.csv")
test_data = pd.read_csv(test_csv)

test_image_names = test_data['Image'].values
test_images = []
for image_name in test_image_names:
    path = os.path.join(dataset_path, "test_images", image_name)
    image = cv2.imread(path)
    test_images.append(image)

test_images = np.array(test_images)
test_images = test_images / 255.0

predictions = model.predict(test_images)
predicted_labels = np.argmax(predictions, axis=1)

predicted_classes = label_encoder.inverse_transform(predicted_labels)

submission_df = pd.DataFrame({'Image': test_image_names, 'Class': predicted_classes})

submission_file = 'submission.csv'
submission_df.to_csv(submission_file, index=False)
