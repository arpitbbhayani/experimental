def analyze_sentiment(text):
    # Define lists of words that indicate positive or negative sentiment
    # These lists can be expanded based on needs
    positive_words = [
        'good', 'great', 'awesome', 'excellent', 'happy', 'love', 'wonderful',
        'fantastic', 'nice', 'beautiful', 'amazing', 'perfect', 'glad', 'joy',
        'exciting', 'delightful', 'pleasant'
    ]
    
    negative_words = [
        'bad', 'terrible', 'awful', 'horrible', 'sad', 'hate', 'disappointing',
        'poor', 'wrong', 'angry', 'upset', 'unfortunate', 'worse', 'worst',
        'miserable', 'unhappy', 'unpleasant'
    ]
    
    # Convert input text to lowercase to ensure matching works regardless of case
    text = text.lower()
    
    # Split the text into individual words for analysis
    words = text.split()
    
    # Count how many positive and negative words appear in the text
    # Using list comprehension with sum() for efficient counting
    positive_count = sum(1 for word in words if word in positive_words)
    negative_count = sum(1 for word in words if word in negative_words)
    
    # Determine the overall sentiment based on which count is higher
    # Returns a tuple containing:
    # 1. The sentiment label (Positive/Negative/Neutral)
    # 2. Count of positive words found
    # 3. Count of negative words found
    if positive_count > negative_count:
        return "Positive", positive_count, negative_count
    elif negative_count > positive_count:
        return "Negative", positive_count, negative_count
    else:
        return "Neutral", positive_count, negative_count

def main():
    # List of example sentences to test the sentiment analyzer
    test_sentences = [
        "I had a wonderful day at the beach, it was beautiful!",
        "This movie was terrible and disappointing.",
        "The weather is nice today.",
        "I hate this bad service, it's horrible.",
        "I'm feeling neutral about this situation."
    ]
    
    # Iterate through each test sentence and analyze its sentiment
    for sentence in test_sentences:
        # Unpack the returned tuple from analyze_sentiment()
        sentiment, pos_count, neg_count = analyze_sentiment(sentence)
        
        # Print the results in a formatted way
        print(f"\nSentence: {sentence}")
        print(f"Sentiment: {sentiment}")
        print(f"Positive words: {pos_count}")
        print(f"Negative words: {neg_count}")
        print("-" * 50)


if __name__ == "__main__":
    main()
