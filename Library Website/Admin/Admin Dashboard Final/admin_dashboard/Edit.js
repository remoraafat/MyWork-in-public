
function displayDetails() {
    var id = localStorage.getItem("bookDetails");
    window.localStorage.removeItem("bookDetails");
    for (let i = 0; i < localStorage.length; i++) {

        let bookkey = localStorage.key(i);
        let book = localStorage.getItem(bookkey);
        let bookdetails = JSON.parse(book);

        if (bookdetails.bookId == id) {
            console.log(bookdetails);
            let container = document.getElementById("container");
            container.innerHTML = "";
            var element = document.createElement("div");
            element.innerHTML = `<h1 class="form-title">Edit Book</h1>
    <form method="post" action="">
        <input type="hidden" id="bookID" value = "${bookdetails.bookId}">
        <div class="image-upload-container">
    <h3>Book Image</h3>
    <label for="image" class="image-upload-label" id="imageurl_newbook">
        <img src="${bookdetails.imageurl}" alt="" id="old" width = 200 height = 200 ><br>
        <label for="image" class="but">Click to Change Image photo</label>
        <input type="file" id="image" accept="image/*" style="display: none;">
    </label>
    <script>
        let old = document.getElementById("old");
        let newimg = document.getElementById("image");

        newimg.onchange = function () {
            old.src = URL.createObjectURL(this.files[0]);
            old.setAttribute("width", 200);
            old.setAttribute("height", 200);
            localStorage.setItem("imageURL${bookdetails.bookId}", JSON.stringify(old.src));
        }
    </script>
</div>

        <label for="bookname"><b>Book Name :</b></label><input type="text" placeholder="Book name" id="bookname"
            class="text-input" value="${bookdetails.bookname}"><br>
        <label for="author"><b>Author :</b></label><input type="text" placeholder="Author name" id="author"
            class="text-input" value="${bookdetails.author}"><br>
        <label for="Category"><b>Category :</b></label><input type="text" placeholder="Category" id="Category"
            class="text-input" value="${bookdetails.category}"><br>
        <label for="Publisher"><b>Publisher :</b></label><input type="text" placeholder="Publisher" id="Publisher"
            class="text-input" value="${bookdetails.publisher}"><br>
        <label for="PublicationDate"><b>Publication Date :</b></label><input type="text" placeholder="Publication Date"
            id="PublicationDate" class="text-input" value="${bookdetails.publicationDate}"><br>
        <label for="NumberofPages"><b>Number of Pages :</b></label><input type="text" placeholder="Number of Pages"
            id="NumberofPages" class="text-input" value="${bookdetails.numberOfPages}"><br>
        <label for="Description"><b>Description :</b></label><br>
        <textarea name="description" cols="70" rows="20" placeholder="Book description" id="Description" >${bookdetails.description}</textarea><br>
        <a href="displaybooks.html"><input type="button" value="Save changes" onclick="updateBookData();" class="but"></a>
        <input type="reset" name="reset" value="Reset" class="but">

    </form>`
            container.appendChild(element);
            break;
        }
    }
}
displayDetails();

function updateBookData() {
    let id = document.getElementById("bookID").value;
    for (let i = 0; i < localStorage.length; i++) {
        let bookKey = localStorage.key(i);
        let book = JSON.parse(localStorage.getItem(bookKey));
        if (book.bookId == id) {
            book.imageurl = document.getElementById("old").src;
            book.bookname = document.getElementById("bookname").value;
            book.author = document.getElementById("author").value;
            book.category = document.getElementById("Category").value;
            book.publisher = document.getElementById("Publisher").value;
            book.publicationDate = document.getElementById("PublicationDate").value;
            book.numberOfPages = document.getElementById("NumberofPages").value;
            book.description = document.getElementById("Description").value;

            localStorage.setItem(bookKey, JSON.stringify(book));
            alert("Data saved");
            break;
        }
    }

}