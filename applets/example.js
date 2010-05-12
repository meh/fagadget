Applet.create('Example', {
    version:     '0.1',
    author:      'Anonymous',
    description: 'This is an example.',

    options: {
        'Something': {
            type:     'String',
            validate: /^\w+$/,
        },

        'Something Else': {
            type: 'Number',
        },
    },

    theme: 'default', // defaults to default anyway

    size: {
        width:  123,
        height: 123,
    },

    onInitialize: function () {
        this.text = new Label({ x: 0, y: 0, width: 100, height: 100 }).bind(this)

        this.images = {
            something:      new Image('something.png', { x: 0, y: 0 }).bind(this).hide(),
            something_else: new Image('something_else.svg', { x: 0, y: 0 }).bind(this).hide(),
        }

        this.text.value = 'HURRRRR'
    },

    onMouseOver: function (event) {
        this.text.value = 'DURRRRR'
    },

    onMouseOut: function (event) {
        this.text.value = 'HURRRRR'
    },

    onMouseClick: function (event) {
        if (event.button == 'left') {
            this.text.hide()
            this.images['something_else'].hide()

            this.images['something'].show()
        }
        else if (event.button == 'right') {
            this.text.hide()
            this.images['something'].hide()

            this.images['something_else'].show()
        }
        else {
            this.images['something'].hide()
            this.images['something_else'].hide()

            this.text.show()
        }
    }
})
