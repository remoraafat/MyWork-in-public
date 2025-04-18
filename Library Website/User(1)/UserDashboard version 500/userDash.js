function addToBorrowedList(bookId) {
    // Get book details from the available books list
    const availableBooksList = document.getElementById("available_books_list");
    const bookToBorrow = availableBooksList.querySelector('li[data-book-id="' + bookId + '"]');
  
    // Confirmation message before borrowing
    if (confirm("Are you sure you want to borrow this book?")) {
    
       const borrowButton = bookToBorrow.querySelector('button');
        borrowButton.remove();
        
        const borrowedBooksList = document.getElementById("borrowed_books_list");
        const borrowedBook = bookToBorrow.cloneNode(true); 
        
        //Add the date of borrowing
        borrowedBook.querySelector('p a').textContent += " (Borrowed on: " + getCurrentDate() + ")" ;
  
         //Add book to the user borrowed book list
        borrowedBook.classList.add("borrowed-book");
        borrowedBooksList.appendChild(borrowedBook);
  
         // Mark the borrowed book as unavailable
        const unavailableSpan = document.createElement('span');
        unavailableSpan.textContent = "Unavailable";
        unavailableSpan.classList.add("unavailable"); 
        bookToBorrow.querySelector('p').appendChild(unavailableSpan);
  
      
      }
     else {
      
    }
  }
  
    function getCurrentDate() {
      var currentDate = new Date();
      var day = currentDate.getDate();
      var month = currentDate.getMonth() + 1;
      var year = currentDate.getFullYear();
      return year + '-' + (month < 10 ? '0' : '') + month + '-' + (day < 10 ? '0' : '') + day;
    }