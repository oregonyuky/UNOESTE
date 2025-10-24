const mongoose = require('mongoose')
const url = 'mongodb://localhost:27017/projeto2'
mongoose.connect(url, {useNewUrlParser: true})
module.exports = mongoose
