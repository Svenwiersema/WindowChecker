import eel

@eel.expose

eel.init('web')

eel.start('test.html', size=(100,100))